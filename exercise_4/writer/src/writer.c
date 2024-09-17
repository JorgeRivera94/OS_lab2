#include "writer.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1000000 * sizeof(int)  // Shared memory size

key_t key;
int shm_id;
int* data;

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

  // write to shared memory
  for (int i = 0; i < 1000000; i++) {
    data[i] = i + 1;
  }

  // detach from memory block
  if (shmdt(data) == -1) {
    perror("Error detaching in shmdt");
    exit(EXIT_FAILURE);
  }
}