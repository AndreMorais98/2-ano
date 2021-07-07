#include <stdio.h>
#include <stdlib.h>


#define MAX_BUFFER 1024


int main (int argc, char** argv){
  char * buffer = (char *) malloc(MAX_BUFFER * sizeof(char));

  int bytes_read = 0;
  int line_counter = 1;
  int newline = 1;

  while (  (bytes_read = read(0,buffer,MAX_BUFFER)) > 0 ){
    char line_number[10] = "";
    if (newline && buffer[0] != '\n'){
      snprintf(line_number,10,"%d:", line_counter);
      write(1, line_number, sizeof(line_number));
      line_counter++;
    }
    write(1, buffer,bytes_read);

    if(buffer[bytes_read - 1] != '\n'){
      newline = 0;
    }
    else{
      newline = 1;
    }
  }
  return 0;
}

