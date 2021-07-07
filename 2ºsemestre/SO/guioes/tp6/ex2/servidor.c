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
    int res;

    if(mkfifo("fifo",0666)== -1){
        perror("mkfifo");
    }

    if ((fd = open("fifo", O_RDONLY)) == -1) {
        perror ("open");
        return -1;
    } else {
        printf("opened fifo for reading\n");
    }


    int logs = open("log.txt",O_CREAT | O_APPEND | O_WRONLY, 0666);

    while(1){
        while((bytes_read = read(fd, &buf, MAX_SIZE))>0) {
            write(logs, &buf, bytes_read);
        }
    }

    if (bytes_read == 0) {
        printf("EOF\n");
    } else {
        perror ("read");
    }

    close(logs);

    unlink("/home/morais/desktop/so/guioes/tp6/ex2/fifo");

    return 0;
}

