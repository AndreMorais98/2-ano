#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main (int argc, char* argv[]) {
    int fd;
    int bytes_read;
    char buf [MAX_SIZE];

    if ((fd = open("fifo", O_WRONLY)) == -1) {
        perror ("open");
        return -1;
    } else {
        printf("opened fifo for writing\n");
    }

    while((bytes_read = read(0, &buf, MAX_SIZE))>0) {
        write(fd, &buf, bytes_read);
    }

    return 0;
}
