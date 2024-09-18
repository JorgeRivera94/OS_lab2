#include "counter_handler.h"

#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void HandleCounters(pid_t* pids, int* count) {
  int selection;
  int index;

  while (1) {
    // print options
    printf("Enter 1 to stop an infinite_counter process.\n");
    printf("Enter 2 to continue an infinite_counter process.\n");
    printf("Enter 3 to reset an infinite_counter process.\n");
    printf("Enter 4 to change the direction of an infinite_counter process.\n");
    printf("Enter 5 to kill an infinite_counter process.\n");

    // get action selection
    printf("Enter your selection: ");
    scanf("%d", &selection);
    if (selection < 1 || selection > 5) {
      printf("Invalid option.\n");
      continue;
    }

    // get process selection
    for (int i = 0; i < *count; i++) {
      printf("Enter %d for process %d\n", i, pids[i]);
    }
    printf("Enter your selection: ");
    scanf("%d", &index);
    if (index < 0 || index >= *count) {
      printf("Invalid option.\n");
      continue;
    }

    // assign the selected pid
    pid_t pid = pids[index];

    // act on the selected process
    switch (selection) {
      case 1:
        kill(pid, SIGSTOP);
        break;
      case 2:
        kill(pid, SIGCONT);
        break;
      case 3:
        kill(pid, SIGUSR1);
        break;
      case 4:
        kill(pid, SIGUSR2);
        break;
      case 5:
        kill(pid, SIGKILL);
        count--;
        for (int e = index; e < *count; e++) {
          pids[e] = pids[e + 1];
        }
        break;
      default:
        printf("Invalid choice.\n");
    }

    // if no process is alive, stop
    if (*count < 1) {
      printf("There are no infinite_counter processes alive. Bye!\n");
      exit(0);
    }
  }
}
