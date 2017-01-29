#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


int main(int argc, char *argv[]){
	if(argc <5){ printf("Hello Program needs 4 arguments...\n"); exit(1);}
	printf("Hello World Program executed\narguments passed: %s %s %s %s\n",argv[1],argv[2],argv[3],argv[4]);
	return 0;
}


























