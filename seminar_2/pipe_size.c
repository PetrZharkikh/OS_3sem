#define GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fds[2];
    pipe(fds);
    size_t sz = fcntl(fds[0], F_GETPIPE_SZ);
    printf("%d\n", sz /4096);
    sz = fcntl(fds[0], F_SETPIPE_S, 40*4096);
     printf("%d\n", sz /4096);
     size_t sz = fcntl(fds[0], F_GETPIPE_SZ);
    printf("%d\n", sz /4096);
    return 0;
}