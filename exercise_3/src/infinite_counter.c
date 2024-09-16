#include "infinite_counter.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Count() {
  // infinite loop
  int* counter = 0;

  while (1) {
    printf("I'm counting and my count is %d", *counter);

    // update counter
  }
}
