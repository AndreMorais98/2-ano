#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    pid_t pid;
    int status;

    for(int i=0;i<10;i++){
        if((pid=fork())==0){
            printf("[proc #%d] pid: %d\n", i, getpid());
            _exit(i);
        }
    }
    for(int i=0;i<10;i++){
         wait(&status);
         printf("[pai %d]\n",WEXITSTATUS(status));
    }
    return 0;
}
