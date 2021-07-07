#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
    int fork, exec, i;

    //começa a 1 para nao apanhar o nome do executavel que se encontra em argv[0]
    for(i=1; i<argc;i++){

        fork = fork();

        if(fork==0){
            printf("Sou o filho %d e vou executar o comando %s\n",getpid(),argv[i]);
            exec=execlp(argv[i],argv[i],NULL)

            perror("reached return");
            _exit(exec);
        }
    }

    for(i=1; i<argc; i++){
        printf("Sou o pai e estou à espera dos filhos\n");
        wait(NULL);
    }
    printf("todos os filhos executaram\n");
    return 0;
}
