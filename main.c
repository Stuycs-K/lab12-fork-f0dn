#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fork_child() {
    pid_t cpid = fork();
    if (!cpid) {
        int pid = getpid();
        srand(pid);
        int wait = rand() % 5 + 1;
        printf("%d %dsec\n", pid, wait);
        sleep(wait);
        printf("%d finished after %d seconds\n", pid, wait);
        exit(wait);
    }
}

int main() {
    int pid = getpid();
    printf("%d about to create 2 processes\n", pid);
    fork_child();
    fork_child();
    int status;
    int cpid = wait(&status);
    printf("Main Process %d is done. Child %d slept for %dsec\n", pid, cpid, WEXITSTATUS(status));
    return 0;
}
