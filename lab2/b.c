#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(){
	printf("SIGINT received...\n");
}
void sigcont_handler(){
	printf("SIGCONT received...\n");
}
int main(){

	//alarm(3);
	signal(SIGINT,sigint_handler);
	signal(SIGCONT,sigcont_handler);
	printf("This process is waiting for somesignal....\n");
	pause(); //paused untill interrupted by some signal...
	printf("Program again resumed ...\n");
	return 0;
}
