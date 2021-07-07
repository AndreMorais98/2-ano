#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define MAX_SIZE 1024

int main (int argc, char * argv[]){
    if(mkfifo("fifo",0666)== -1){
        perror("mkfifo");
    }
    return 0;
}

