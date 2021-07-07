#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "ex4.h"


char read_buffer[MAX_READ_BUFFER];
int read_buffer_pos = 0;
int read_buffer_end = 0;

//readline char a char
ssize_t readln(int fd, void *buf, size_t size){
  int res=0;
  //char *buffer = (char*)buf;
  int i = 0;

  while(i<size && (res = readc(fd, &buf[i] > 0))){
    i++;
    if (((char*) buf)[i-1] == '\n')
      return i;
  }
  return i;
}


//ler 1 char
int readc(int fd, char* c){
  if(read_buffer_pos == read_buffer_end){
    read_buffer_end = read(fd,read_buffer,MAX_READ_BUFFER);}
  switch(read_buffer_end){
    case -1:
      perror("Rip");
      return -1;
      break;
    case 0:
      return 0;
      break;
    default:
    read_buffer_pos = 0;
  }
    *c = read_buffer[read_buffer_pos++]

    return 1;
}



int main (int argv, char** argc){

  if(argc < 2) {
      printf("USAGE: %s filename\n", *argv);
      printf("list a file name on the command line to be read and printed\n");
      B
      return 1;
      // In Unix: exit(1);
  }
  B
  if ((fp = fopen(argv[1], "r")) == NULL) {
      printf("cannot open file %s\n", argv[1] );
      return 1;
  while( ReadLine(line, MAXLINE, fp) ) {
      printf( "%s\n", line );
  }
  fclose(fp);
  return 0;
}

