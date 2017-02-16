#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
int i;
//close(1);
for(i = 0;i<=atoi(argv[1]);i++){
	char str[100];
	sprintf(str,"/dev/pts/%d",i);
	int fd = open(str,O_WRONLY);
	if(write(fd,"Hello Wold...this is shit\n",25)) printf("%d: write to %d successfulll....\n",i,fd);
	close(fd);
}
return 0;
}
