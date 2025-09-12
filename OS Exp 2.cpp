#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

   
    pid = fork();

    if (pid < 0) {
       
        printf("Process creation failed.\n");
    } 
    else if (pid == 0) {
        
        printf("Child Process:\n");
        printf("Process ID (PID): %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
    } 
    else {
        
        printf("Parent Process:\n");
        printf("Process ID (PID): %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
    }

    return 0;
}
