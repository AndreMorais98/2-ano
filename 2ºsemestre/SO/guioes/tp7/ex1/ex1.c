#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main (){
    int p[2];
    char linha[] = "ola\n";
    char buffer[40];
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
            read(p[0], &buffer, sizeof(buffer));
            printf("FILHO leu : %s \n",buffer);
            close(p[0]);
            _exit(0);


//PROCESSO PAI
        default:
            close(p[0]); //PAI fecha o de leitura
            sleep(5);
            write(p[1], &linha, sizeof(linha));
            printf("PAI escreveu : %s \n",linha);
            close(p[1]);
            wait(&status);
    }
  return 0;
}

