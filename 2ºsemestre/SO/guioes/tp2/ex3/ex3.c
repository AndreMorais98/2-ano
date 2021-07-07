#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    pid_t pid;
    int status;

    for(int i=0;i<10;i++){
        if((pid=fork())==0){
            printf("[proc #%d] pid: %d & pid do pai: %d\n",i, getpid(),getppid());
            _exit(i);
        }
        else{
            wait(&status);
            printf("[pai %d]\n",WEXITSTATUS(status));   // para imprimri o outpu do _exit(i)
            sleep(1);
        }
    }
    return 0;
}
