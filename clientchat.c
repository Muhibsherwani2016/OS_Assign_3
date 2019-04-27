#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234

// Creaton Of Shared Memory
int shmget(key_t key, size_t size, int shmflg)

// Creation Of Semaphore
int semget(key_t key, int num_sems, int sem_flags);

// Changing Value of Semaphore
int semop(int sem_id, struct sembuf *sem_ops, size_t num_sem_ops);

// Deletion Of Shared Memory
if (shmdt(shared_memory) == -1) {
fprintf(stderr, “shmdt failed\n”);
exit(EXIT_FAILURE);
}
if (shmctl(shmid, IPC_RMID, 0) == -1) {
fprintf(stderr, “shmctl(IPC_RMID) failed\n”);
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}


// Deletion Of Semaphores
void remove_semaphore() {
   int semid;
   int retval;
   semid = semget(SEM_KEY, 1, 0);
      if (semid < 0) {
         perror("Remove Semaphore: Semaphore GET: ");
         return;
      }
   retval = semctl(semid, 0, IPC_RMID);
   if (retval == -1) {
      perror("Remove Semaphore: Semaphore CTL: ");
      return;
   }
   return;
}
