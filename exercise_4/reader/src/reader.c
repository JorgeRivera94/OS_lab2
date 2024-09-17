#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define SHM_SIZE 1000000 * sizeof(int)  // Shared memory size

key_t key;
int shm_id;
int* data;
long long sum;

// structs to measure elapsed time
struct timespec start;
struct timespec end;

void Write() {
  // create a key
  key = ftok("temp", 616);
  if (key == -1) {
    perror("Error with ftok key creation.");
    exit(EXIT_FAILURE);
  }
  printf("Key: %d", key);

  // request memory block
  shm_id = shmget(key, SHM_SIZE, 0777 | IPC_CREAT);
  if (shm_id == -1) {
    perror("Error requesting the block with shmget.");
    exit(EXIT_FAILURE);
  }
  printf("Mem id: %d", shm_id);

  // attach memory block to process
  data = (int*)shmat(shm_id, NULL, 0);
  if (data == (int*)-1) {
    perror("Error in shmat.");
    exit(EXIT_FAILURE);
  }

  // get start time
  clock_gettime(CLOCK_MONOTONIC, &start);

  // read from shared memory and add the values
  for (int i = 0; i < 1000000; i++) {
    sum += data[i];
  }

  // get end time
  clock_gettime(CLOCK_MONOTONIC, &end);

  printf("The sum of the values is: %lld", sum);

  // detach from memory block
  if (shmdt(data) == -1) {
    perror("Error detaching in shmdt");
    exit(EXIT_FAILURE);
  }

  // free the memory block
  shmctl(shm_id, IPC_RMID, NULL);

  // print out the elapsed time for reading
  double elapsed_time =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Time elapsed to read from the shared memory block: %f seconds.\n",
         elapsed_time);
}