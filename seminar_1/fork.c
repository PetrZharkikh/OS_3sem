#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(){
    int fds[2];
    pipe(fds);
    pid_t pid = fork();
    printf("PID %d\n", pid);
    if (pid > 0){
        printf("Parent %d\n", getpid());
        write(fds[1], "hello", 6);
        int status = 0;
        printf("code returned from child %d\n", waitpid(pid, &status, WNOHANG));
        printf("ret code: %d\n", WEXITSTATUS(status));

    }
    else if (pid == 0) {
        fflush(stdout);
        char buf[4096];
        int ret = read(fds[0], buf, sizeof(buf));
        printf("From parent: %s, %d bytes len\n", buf, ret);
        return 43;
    }
    return 0 ;
}
