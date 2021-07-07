#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


int mysystem (char* command) {

  int status;

  if(fork()==0) {
    system(command);
    _exit(0);
  }

  return 0;
}


int main(int argc, char** argv){

    char comando1[] = "ls -l -a -h";
    char comando2[] = "sleep 5";
    char comando3[] = "ps";
    int ret;

    printf("a executar myssystem para %s\n",comando1);
    ret = mysystem(comando1);
    printf("ret: %d\n",ret);


    printf("a executar myssystem para %s\n",comando2);
    mysystem(comando2);


    printf("a executar myssystem para %s\n",comando3);
    mysystem(comando3);

    return 0;
}

