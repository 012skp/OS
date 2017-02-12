#include <bits/stdc++.h>
#include <unistd.h>
#include <signal.h>


int main(){

	char str[100];
	bzero(str,100);
	scanf(" %[^\n]",str);
	//strcpy(str, "cat hello.c | grep Hello");
	int fd[2];
	pipe(fd);
	int pid = fork();
	if(pid < 0) printf("fork failed..\n");
	if(pid == 0){
		printf("this is child..\n");
		if(dup2(fd[0],0) == -1) printf("dup2 error child..\n");
		char *cmd = strchr(str,'|');
		if(cmd != NULL) 
		printf("%s\n",cmd);
		system(cmd+1);
		close(fd[0]);
	}
	else{
		printf("this is parent\n");
		int stdin_; 
		dup2(1,stdin_);
		dup2(fd[1],1);
		char *cmd = strchr(str,'|');
		char cc[100];
		strncpy(cc,str,cmd-str-1);
		printf("%s\n",cc);
		system(cc);
		write(fd[1],"^D",2);
		dup2(stdin_,1);
		printf("parent exitingafadsfadsfad....\n");
		exit(1);

	}
	printf("exiting...\n");
	return 0;
}