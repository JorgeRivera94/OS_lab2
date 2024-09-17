#include "infinite_counter.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void Handler1
void Handler(int signal, int* counter, int* direction) {
  if (signal == SIGUSR1) {
    *counter = 0;
  } else if (signal == SIGUSR2) {
    *direction = -1 * (*direction);
  }
}
void Count() {
  int counter = 0;
  int direction = 1;
  int* counter_ptr = &counter;
  int* direction_ptr = &direction;

  // infinite loop
  while (1) {
    printf("I'm counting and my count is %d\n", counter);

    // update counter
    counter += direction;
    sleep(1);
  }
}
