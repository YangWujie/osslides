#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int x = 0;
    printf("hello world (pid:%d)\n", (int) getpid());
    for (int d = 0; d < 4; d++) {
        int rc = fork();
        x *= 2;
        if (rc < 0) {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc == 0) {
            // child (new process)
        } else {
            // parent goes down this path (original process)
            x++;
            wait(NULL);
        }
    }

    printf("pesudo id: %d\n", x);

    return 0;
}
