#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX_BUF 1024

int main()
{
    int fd;
    char * myfifo = "myfifo";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    if(fd == -1){perror("open failed"); exit(1);} 
    printf("opend....\n");
    read(fd, buf, MAX_BUF);
    printf("Received: %s\n", buf);
    close(fd);
    /* remove the FIFO */
    unlink(myfifo);
    return 0;
}