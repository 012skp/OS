#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	int segment_id = atoi(argv[1]);
	char *shared_memory;
	shared_memory = (char*)shmat(segment_id,NULL,0);
	if(shared_memory == (void*)-1){ perror("error:"); exit(0);}
	printf("from shared memory:%s\n",shared_memory);
	shmdt(shared_memory);

return 0;
}
