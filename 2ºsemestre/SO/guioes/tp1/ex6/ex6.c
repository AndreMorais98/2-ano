#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "person.h"


int main(int argc, char** argv){
  if(argc < 4){
    printf("Número de inputs inválido");
    return -1;
  }

  open("pessoas.txt", O_CREAT );

  if (strcmp(argv[1],"-i")==0){
    char* name = argv[2];
    int age = atoi(argv[3]);
    new_person(name,age);

  }

  if (strcmp(argv[1], "-u")==0){
    char* name = argv[2];
    int age = atoi(argv[3]);
    person_change_age(name,age);
  }
  return 0;
}


