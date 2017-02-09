#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	if(argc == 2) shmctl(atoi(argv[1]),IPC_RMID,NULL); 
return 0;
}
