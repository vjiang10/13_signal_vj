#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static void sighandler(int signo) {
    if (signo == SIGUSR1) 
        printf("parent process PID: %d\n", getppid());
    if (signo == SIGINT) {
        // creating and appending message to new file out.txt
        int file = open("out.txt",  O_CREAT | O_APPEND | O_RDWR, 0777);
        char msg[] = "exited due to SIGINT\n";
        write(file, msg, strlen(msg));
        close(file);
        printf("\t%s", msg);
        exit(0);
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while (1) {
        printf("process PID: %d\n", getpid());
        sleep(1);
    }

    return 0;
}