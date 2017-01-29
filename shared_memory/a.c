#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	int segment_id;
	char *shared_memory;
	int size = 4096;
	if(argc != 2) segment_id = shmget(IPC_PRIVATE,size,S_IRUSR|S_IWUSR);
	if(argc == 2) segment_id = atoi(argv[1]);
	printf("shmid = %d\n",segment_id);
	if(segment_id == -1){ perror("error: "); exit(0);}
	shared_memory = (char*)shmat(segment_id,NULL,0);
	if(argc != 2) sprintf(shared_memory,"Hi there...");
	printf("from shared memory:%s\n",shared_memory);
	shmdt(shared_memory);

return 0;
}
