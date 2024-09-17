#include "reader.h"

#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <time.h>

#define QUEUE_NAME "/test_queue"
#define MAX_SIZE 1024
#define NUM_INTS 1000000

mqd_t mq;
struct mq_attr attr;
char buffer[MAX_SIZE];

// structs to measure elapsed time
struct timespec start;
struct timespec end;

void Write() {
  // open the message queue
  mq = mq_open(QUEUE_NAME, O_RDONLY);
  if (mq == (mqd_t)-1) {
    perror("mq_open");
    exit(EXIT_FAILURE);
  }

  // get start time

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