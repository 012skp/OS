#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int fd;
    char * myfifo = "myfifo";

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    /* write "Hi" to the FIFO */
    fd = open(myfifo, O_WRONLY); //BLOCKS untill someone opens myfifo in Read Mode
    printf("opend....\n");
    write(fd, "Hi", sizeof("Hi"));
    close(fd);


    return 0;
}