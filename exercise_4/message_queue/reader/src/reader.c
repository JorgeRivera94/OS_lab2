#include "reader.h"

#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <time.h>

#define QUEUE_NAME "/test_queue"
#define MAX_SIZE 1024
#define NUM_INTS 1000000

// message queue
mqd_t mq;
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
  if (mq_receive(mq, buffer, MAX_SIZE, NULL) == -1) {
    perror("mq_receive");
    exit(1);
  }
  sscanf(buffer, "%ld.%09ld", &start.tv_sec, &start.tv_nsec);

  // read from shared memory and add the values
  long long sum = 0;
  for (int i = 0; i < NUM_INTS; i++) {
    if (mq_receive(mq, buffer, MAX_SIZE, NULL) == -1) {
      perror("mq_receive");
      exit(EXIT_FAILURE);
    }
    sum += atoi(buffer);
  }

  // get end time
  clock_gettime(CLOCK_MONOTONIC, &end);

  // print values
  printf("The sum of the values is: %lld", sum);

  // calculate elapsed time
  double elapsed_time =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("Time elapsed to read from the shared memory block: %f seconds.\n",
         elapsed_time);

  // Close the message queue
  if (mq_close(mq) == -1) {
    perror("mq_close");
    exit(1);
  }

  // Unlink the message queue
  if (mq_unlink(QUEUE_NAME) == -1) {
    perror("mq_unlink");
    exit(1);
  }
}