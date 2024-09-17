#include "writer.h"

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1000000 * sizeof(int)  // Shared memory size

key_t key;
int shm_id;
char* data;

void Write() {
  // create a key
  key = ftok("/tmp", 616);
  if (key == -1) {
    perror("Error with ftok key creation.");
    exit(EXIT_FAILURE);
  }

  // request memory block
  shm_id = shmget(key, SHM_SIZE, 0774 | IPC_CREAT);
  if (shm_id == -1) {
    perror("Error requesting the block with shmget.");
    exit(EXIT_FAILURE);
  }

  // attach memory block to process
  data = (char*)shmat(shm_id, NULL, 0);
  if (data == (char*)-1) {
    perror("Error in shmat.");
    exit(EXIT_FAILURE);
  }

  // write to shared memory
  for (int i = 0; i < 1000000; i++) {
    strcpy(data[i], i + 1);
  }

  // detach from memory block
  shmdt(data);
}