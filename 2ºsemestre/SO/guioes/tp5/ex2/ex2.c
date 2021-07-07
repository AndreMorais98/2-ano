#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main (){
    int p[2];
    char * linhas[] = {"ola\n", "ole\n","oli\n"};
    char buffer;
    int nr_linhas=3;
    int status;


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
            close(p[1]); //FILHO fecha o de escrita
            while(read(p[0], &buffer, 1) > 0){
                printf("Filho leu : %c \n",buffer);
            }
            close(p[0]);
            _exit(0);


//PROCESSO PAI
        default:
            close(p[0]); //PAI fecha o de leitura
            for (int i=0; i < nr_linhas; i++){
                 write(p[1], linhas[i], strlen(linhas[i]));
                 printf("PAI escreveu : %s \n",linhas[i]);
            }
            close(p[1]);
            wait(&status);
    }
  return 0;
}

