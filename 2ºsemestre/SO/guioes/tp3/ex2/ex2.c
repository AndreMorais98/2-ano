#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
    pid_t pid;
    int status;

    if((pid=fork())==0){
        execlp("ls","ls","-l",NULL);
    }
    else{
        wait(&status);
        printf("[pai %d]\n",WEXITSTATUS(status));
    }

    return 0;
}
