#include "greetings.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Greet() {
  // process ID
  pid_t pid;

  // print message
  printf("hello there, I'm process %d\n", getpid());

  // wait 10s
  sleep(10);

  // print second message
  printf("I'm done, bye!\n");
}