#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER 4096
#define MAX_READ_BUFFER 2048

ssize_t readln(int fd, void *buf, size_t size);
