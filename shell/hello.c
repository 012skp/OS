#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	printf("Hello World..\n");
	printf("Arguments are..\n");
	int i=1;
	for(i=1;i<argc;i++)printf("%s\n",argv[i]);
	char str[] = "Hello My name is Shailesh";
	int cnt = 0;
	char* sss;
	i=0;
	sss = strtok(str," ");
	printf("no of strings = %d\n",cnt);
	while(sss!= NULL){
		printf("%s\n",sss);
		sleep(1);
		sss = strtok(NULL," ");
	}
	/*
	char prog[] = "cat";
	char* const args[] = {prog,"shell.cc",NULL};
	if(execvp(prog,args) == -1) perror("execvp");
	return 0;
	*/
}
