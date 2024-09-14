#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main(){
    size_t size = 4096 * sizeof(int);
    void *ptr = NULL;
    ptr = mmap(0, size, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (ptr == NULL) return 1;
    int *shared = ptr;

    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        printf("In child: %d\n", shared[5]);
    }
    else {
        shared[5] = 56712;
    }

    return 0;
}