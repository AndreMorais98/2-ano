#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main (){
    int p[2];


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
            dup2(p[0],0);
            execlp("wc","wc","-l",NULL);
            close(p[0]);

            //PROCESSO PAI
        default:
            close(p[0]); //PAI fecha o extremo de leitura
            dup2(p[1],1);
            execlp("ls","ls","/etc",NULL);
            close(p[1]);
        }
    return 0;
}

/* Mesmo exercício mas com 2 filhos */

/* int main(){ */
/*     int pfd[2]; */
/*     char buf[10]; */
/*     pipe(pfd); */

/*     if (!fork()) { // outro filho */
/*         dup2(pfd[0], 0); // std input */
/*         close(pfd[1]); // fecha o descritor de escrita */
/*         execlp("wc", "wc","-l", NULL); */
/*     } */


/*     if (!fork()) { */
/*       dup2(pfd[1], 1); // std output */
/*       close(pfd[0]); // fecha o descritor de leitura */
/*       execlp("ls", "ls", "/etc", NULL); */
/*     } */

/*     close(pfd[0]); */
/*     close(pfd[1]); */

/*     return 0; */
/* } */

