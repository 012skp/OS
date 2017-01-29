#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>


void sigchld_handler(){printf("SIGCHLD signal received...\n");}
void sigterm_handler(){printf("SIGTERM siganl received...\n");}
void sigint_handler(){printf("SIGINT signal received...\n");}
void sigcont_handler(){printf"SIGCONT signal received...\n");}


int main(){

int pid = fork();
if(pid == 0){
	printf("I am child pid = %d\n",getpid());
	//while(1);
	sleep(200);
}
else{
	signal(SIGCHLD,sigchld_handler); //handles for child status change...

	printf("I am parent pid = %d\n",getpid());
	//while(1);
	sleep(200);
}



return 0;
}
