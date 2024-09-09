#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void run_cmd(const char *cmd){
    const pid_t pid = fork();
    if (pid < 0) {
        exit(1);
    }
    if (pid>0){
        waitpid(pid, NULL, 0);
        return;
    }
    else {
        char** args = pars_cmd(cmd);
        execvp(args[0], args);
        printf("exec failed\n");
        }
        return;
}

int main(){
    while(1) {
        char* cmd;
        run_cmd(cmd);
    }
    return 0;
}