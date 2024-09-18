#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    perror("Program counter_handler needs at least one pid as argument.");
    exit(EXIT_FAILURE);
  }

  int count = argc - 1;
  pid_t pids[count];

  for (int i = 0; i < count; i++) {
    // convert the argv strings to pid_t to populate the array
    pids[i] = (pid_t)atoi(argv[i + 1]);
  }

  HandleCounters(pids, &count);

  return 0;
}