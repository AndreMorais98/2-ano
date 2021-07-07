#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int res;
    res=execl("/bin/ls","ls","-l",NULL);
    //execlp("ls","ls","-l",NULL);

    perror("ERROR");


    //return 0;
    return res;
}
