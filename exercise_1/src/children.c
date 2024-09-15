#include "children.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

void CreateChildren() {
  pid_t id;
  pid_t cid;

  for (int i = 0; i < 3; i++) {
    id = fork();  // 0 for children
    if (id == 0) {
      printf("I’m a child, and my id is: %d\n", getpid());
      for (int j = 0; j < 2; j++) {
        cid = fork();
        if (cid == 0) {
          execlp("./greetings", "./greetings", NULL);
          exit(0);
        }
      }
      while (wait(NULL) > 0);  // wait returns pid of the terminated child
      exit(0);
    }
  }
  while (wait(NULL) > 0);
}