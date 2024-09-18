#include "terminal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void HandleCommands(char* command) {
  char* commands[20];
  char* separated;
  int i = 0;

  // separate the input
  separated = strtok(command, ";");
  while (separated != NULL) {
    commands[i++] = separated;
    separated = strtok(NULL, ";");
  }
  commands[i] = NULL;

  for (int j = 0; j < i; j++) {
    char* args[20];
    char* token;
    int k = 0;

    // separate the arguments
    token = strtok(commands[j], " ");
    while (token != NULL) {
      args[k++] = token;
      token = strtok(NULL, " ");
    }
    args[k] = NULL;

    int id = fork();

    if (id == 0) {
      execvp(args[0], args);
    }

    // wait for child to terminate
    wait(NULL);
  }
}