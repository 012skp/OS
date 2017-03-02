#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void* f(void* arg){
	while(1) printf("thread ... pid = %d  ppid = %d\n",getpid(),getppid());
}


int main(){

	pthread_t t;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&t,&attr,f,NULL);
	int ret = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(ret == 0) sleep(1);
	printf("main thread will die after 5 sec..\n");
	sleep(2);
	return 0;
}