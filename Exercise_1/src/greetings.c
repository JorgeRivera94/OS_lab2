#include "greetings.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Greet() {
  pid_t pid;
  printf("hello there, I’m process %d\n", getpid());
}