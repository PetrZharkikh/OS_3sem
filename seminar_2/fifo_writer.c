#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>          

#define FIFO_NAME "fifo_example"

int main() {
    int ret = mknod(FIFO_NAME, 0666 | S_IFIFO, 0);
    if (ret == -1) {
        perror("fifo creation");
        //return -1;
    }
    int fd = open(FIFO_NAME, O_WRONLY);

    int size;
    int buf[4096];

    while ((size = read(0, buf, sizeof(buf)-1))>0){
    buf[size] = '\0'; //delete in reader
    write(fd, buf, size);
    }
    
    return 0;
}

//for rider change O_RONLY and delete mknod also read->1
//rm fifo_example
//create "fifo_reader" same way
//while is not necessary
//страничный кэш
//