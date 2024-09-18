#include "infinite_counter.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// initial values for count and direction
int counter = 0;
int direction = 1;

// signal handler
void Handler(int signal) {
  if (signal == SIGUSR1) {
    counter = 0;
  } else if (signal == SIGUSR2) {
    direction = -1 * direction;
  }
}

void Count() {
  printf("My pid is %d", getpid());

  // sigaction for signals
  struct sigaction sa1;
  sa1.sa_handler = Handler;
  sigaction(SIGUSR1, &sa1, NULL);

  struct sigaction sa2;
  sa2.sa_handler = Handler;
  sigaction(SIGUSR2, &sa2, NULL);

  // infinite loop
  while (1) {
    printf("I'm counting and my count is %d\n", counter);

    // update counter
    counter += direction;
    sleep(1);
  }
}
