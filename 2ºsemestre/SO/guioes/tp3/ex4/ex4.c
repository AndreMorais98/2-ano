#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    /* for(int i=0;i<argc;i++){ */
    /*     if(i==0){ */
    /*         write(1,argv[i]+2,strlen(argv[i])-2); */
    /*     } */
    /*     else{ */
    /*         write(1,argv[i],strlen(argv[i])); */
    /*     } */

    /*     write(1,"\n",1); */
    /* } */

    strcpy(argv[0],"ex4");
    //execv("/home/morais/desktop/so/guioes/tp3/ex3",argv);
    execv("./ex3",argv);
    return 0;
}
