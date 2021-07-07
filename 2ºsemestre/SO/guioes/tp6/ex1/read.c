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

    if ((fd = open("fifo", O_RDONLY)) == -1) {
        perror ("open");
        return -1;
    } else {
        printf("opened fifo for reading\n");
    }

    // sleep (15);

    while((bytes_read = read(fd, &buf, MAX_SIZE))>0) {
        write(1, &buf, bytes_read);
    }

    if (bytes_read == 0) {
        printf("EOF\n");
    } else {
        perror ("read");
    }

    return 0;
}

