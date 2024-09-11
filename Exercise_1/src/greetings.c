#include "greetings.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void Greet() {
  // process ID
  pid_t pid;

  // print message
  printf("hello there, I’m process %d\n", getpid());

  // wait 10s
  sleep(10);

  // print second message
  printf("I’m done, bye!\n");
}

// here the progam that creates 3 children
void CreateChildren() {
  pid_t id;
  pid_t cid;

  for (int i = 0; i < 3; i++) {
    id = fork();  // 0 para children
    if (id == 0) {
      printf("I’m a child, and my id is: %d\n", getpid());
      for (int j = 0; j < 2; j++) {
        cid = fork();
        if (cid == 0) {
          printf("inner child %d\n", getpid());
          exit(0);
        }
      }
      exit(0);
    }
  }

  printf("This is the parent pid: %d\n", getpid());
}