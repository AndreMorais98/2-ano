#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "person.h"

void new_person (char* name,int age){
  int fd=open("pessoas.txt", O_WRONLY | O_APPEND, 0777);
  Person p;
  p.age = age;
  strcpy(p.name,name);
  write(fd,&p,sizeof(struct Person));
  close(fd);
}

void person_change_age (char* name, int age){
  Person p; int res;
  int fd = open("pessoas.txt", O_WRONLY, 0777);
  while((res=read(fd,&p,sizeof(struct Person))>0)){
      if(strcmp(name,p.name)==0){ // strcmp = 0 , verdade
        p.age=age;
        lseek(fd,-sizeof(struct Person),SEEK_CUR);//ler a struct person o offset fica a frente da lida
        write(fd,&p,sizeof(struct Person));
        close(fd);
      }
  }
}
