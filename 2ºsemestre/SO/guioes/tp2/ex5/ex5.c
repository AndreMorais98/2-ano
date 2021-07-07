#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    int status;

    for(int i=0; i<10; i++){
        if((pid=fork())==0){
            printf("[proc #%d] & pai %d\n", getpid(),getppid());
        }
        else{
            wait(&status);
            _exit(0);
           // MACRO DO STOR PARA DAR WAIT
           // pid_t terminated_pid = wait(&status);

           // if (WIFEXITED(status)){
           //     printf("[pai] process %d exited. exit code %d\n", terminated_pid, WEXITSTATUS(status));
           // } else {
           //     printf("[pai] process %d exited.\n", terminated_pid);
           // }
           // _exit(0);
        }
    }

    printf("saí ciclo pid %d\n",getpid());

    _exit(0);


    return 0;
}
