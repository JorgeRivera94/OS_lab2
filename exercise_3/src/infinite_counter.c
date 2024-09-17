#include "infinite_counter.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void Handler1
void Count() {
  int counter = 0;
  int direction = 1;

  // infinite loop
  while (1) {
    printf("I'm counting and my count is %d\n", counter);

    // update counter
    counter += direction;
    sleep(1);
  }
}
