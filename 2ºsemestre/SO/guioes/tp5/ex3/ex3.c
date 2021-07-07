#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main (){
    int p[2];
    char buffer[40];


    //VERIFICA SE CRIA O PIPE OU NAO
    if(pipe(p)==-1){
        perror("Nao criou o pipe");
        return -1;
    }

    switch(fork()){
        case -1:
            perror("Nao criou o fork");
            return -1;

            //PROCESSO FILHO
        case 0:
            close(p[1]); //FILHO fecha o extremo de escrita
            dup2(p[0],0);
            close(p[0]);
            execlp("wc","wc",NULL);

            //PROCESSO PAI
        default:
            close(p[0]); //PAI fecha o de leitura
            while(read(0, &buffer , sizeof(buffer)) > 0){
                printf("FILHO leu : %s \n",buffer);
                write(p[1],&buffer,sizeof(buffer));
            }
            close(p[1]);
        }
    return 0;
}

