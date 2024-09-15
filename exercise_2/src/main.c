#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // will process the string before passing it to HandleCommands

  char command[100];  // big size in case there is a file path

  while (1) {
    printf("> ");
    if (fgets(command, sizeof(command), stdin) == NULL) {
      break;
    }

    command[strcspn(command, "\n")] = 0;  // find and remove newline charater
    if (strcmp(command, "exit") == 0) {
      break;
    }

    HandleCommands(command);
  }

  return 0;
}