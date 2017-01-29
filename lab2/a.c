#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>
#include<signal.h>
#include<sys/prctl.h>
int pid;
void sigchld_handler(){
	int status;
	wait(pid,&status,WNOHANG);
	if(WIFEXITED(status)) printf("Child exited with exit status %d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status)) printf("Child terminated by signal %d\n",WTERMSIG(status));
	else if(WIFSTOPPED(status)) printf("Child stopped by signal %d\n",WSTOPSIG(status));
	else if(WIFCONTINUED(status)) printf("Child resumes its execution...\n");
	else printf("Child status change is unknown...\n");
}


int main(){
	pid = fork();
	if(pid==0){
			
			printf("I am child pid =%d, pgid = %d\n",getpid(),getpgid(0)); 
			prctl(PR_SET_PDEATHSIG,SIGTERM);// asks kernel to deliever SIGTERM when parent terminates...
			printf("I am child doing infinite work...");
			while(1) sleep(1);
			
	}
	else{
		signal(SIGCHLD,sigchld_handler);//signal_handler for any change in child's status....
		printf("Parent pid = %d pgid = %d\n",getpid(),getpgid(0)); 		
		printf("I am parent sleeping for 150 sec but I will monitor my child for any status change....\n");
		sleep(150);
		struct timeval tv;
		int b=gettimeofday(&tv,NULL);
		printf("\nStat:%d",b);
		printf("sec = %lld and usec = %d ",(long long int)tv.tv_sec, (int)tv.tv_usec);
		tv.tv_sec = tv.tv_sec + (time_t)3600; //increasing time by 1hr....
		int a = settimeofday(&tv,NULL);
		printf("\nstat:%d",a);
	}

	return 0;
}
