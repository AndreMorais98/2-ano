#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_READ_BUFFER 1024

ssize_t readln(int fildes, void* buf, ssize_t nbyte){
  ssize_t size = 0;
  int res;
  char byte;
  char *buffer = (char*)buf; // casting void*
  while ((res = read(fildes,&byte,1) > 0) && size < nbyte){
    if (byte == '\0' || byte == '\n'){
      buffer[size]='\0';
      return size;
    }
    buffer[size++] = byte;
  }
  return size;
}


int main (int argc, char** argv){
  char buff[MAX_READ_BUFFER];
  while(readln(0,buff,1024)>0)
    printf("%s\n",buff);
  return 0;
}
