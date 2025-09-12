#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    char *str = (char *)shmat(shmid, NULL, 0);

    if (fork() == 0) {
        // Child process writes to shared memory
        char message[] = "Hello from child process!";
        strcpy(str, message);
        printf("Child: Written message to shared memory.\n");
    } else {
        // Parent process reads after a short delay
        sleep(1);
        printf("Parent: Read from shared memory: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
