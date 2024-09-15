#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void HandleCommands(char* command) {
  char* args[20];
  char* separated;
  int i = 0;

  // separa the input
  separated = strtok(command, " ");
  while (separated != NULL) {
    args[i++] = separated;
    separated = strtok(NULL, " ");
  }
  args[i] = NULL;

  int id = fork();

  if (id == 0) {
    execvp(args[0], args);
  }

  // wait for child to terminate
  wait(NULL);
}