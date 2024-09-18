#include "writer.h"

#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define QUEUE_NAME "/test_queue"
#define MAX_SIZE 1024
#define NUM_INTS 1000000

mqd_t mq;
struct mq_attr attr;
char buffer[MAX_SIZE];

// initialize the queue attributes
attr.mq_flags = 0;
attr.mq_maxmsg = 10;
attr.mq_msgsize = MAX_SIZE;
attr.mq_curmsgs = 0;

// structures to store elapsed time
struct timespec start;
struct timespec end;

void Write() {
  // Create the message queue
  mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY | O_NONBLOCK, 0644, &attr);
  if (mq == (mqd_t)-1) {
    perror("Error creating the queue with mq_open");
    exit(EXIT_FAILURE);
  }
  if (mq == (mqd_t)-1) {
    perror("Error creating the queue with mq_open.");
    exit(EXIT_FAILURE);
  }

  // get start time
  clock_gettime(CLOCK_MONOTONIC, &start);

  // send the start time as the first message
  sprintf(buffer, MAX_SIZE, "%ld %ld", start.tv_sec, start.tv_nsec);
  if (mq_send(mq, buffer, MAX_SIZE, 0) == -1) {
    perror("Error sending start time in mq_send.");
    exit(EXIT_FAILURE);
  }

  // send 1,000,000 messages
  for (int i = 1; i <= NUM_INTS; i++) {
    snprintf(buffer, MAX_SIZE, "%d", i);

    if (mq_send(mq, buffer, MAX_SIZE, 0) == -1) {
      perror("Error sending start time in mq_send.");
      exit(EXIT_FAILURE);
    }
  }

  // Close the message queue
  if (mq_close(mq) == -1) {
    perror("mq_close");
    exit(EXIT_FAILURE);
  }
}