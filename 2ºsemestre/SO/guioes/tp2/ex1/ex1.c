#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv){
  pid_t pid;

  if((pid=fork())==0){
    printf("pid do filho -> %d \npid do pai -> %d \n", getpid(),getppid());
    sleep(10);
  }
  else{
    printf("pid do pai -> %d \npid do avô -> %d \n",getpid(),getppid());
    sleep(10);
  }
  return 0;
}
