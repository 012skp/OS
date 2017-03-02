#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>


using namespace std;


int n;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int flag;

void handle_sigcont5(int signal){
	if(signal == SIGCONT){
		printf("SIGCONT5 received...\n" );
	}
}
void handle_sigcont10(int signal){
	if(signal == SIGCONT){
		printf("SIGCONT10 received...\n" );
	}
}
void handle_sigcont15(int signal){
	if(signal == SIGCONT){
		printf("SIGCONT15 received...\n" );
	}
}
void handle_sigcont20(int signal){
	if(signal == SIGCONT){
		printf("SIGCONT20 received...\n" );
	}
}





void* inc5(void *a){
	signal(SIGCONT,handle_sigcont5);
	printf("Inside inc5 \n");
	if(flag) pthread_mutex_lock(&m);
	int p = n;
	p++;
	n = p;
	if(flag) pthread_mutex_unlock(&m);
	int nn = 0;
	while(1);
}

void* inc10(void *a){
	signal(SIGCONT,handle_sigcont10);
	printf("Inside inc10 \n");
	if(flag) pthread_mutex_lock(&m);
	int p = n;
	p++;
	n  = p;
	if(flag) pthread_mutex_unlock(&m);
}

void* inc15(void *a){
	printf("Inside inc15 \n");
	if(flag) pthread_mutex_lock(&m);
	int p = n;
	p++;
	n = p;
	if(flag) pthread_mutex_unlock(&m);
}

void* inc20(void *a){
	printf("Inside inc20  \n");
	if(flag) pthread_mutex_lock(&m);
	int p = n;
	p++;
	n = p;
	if(flag) pthread_mutex_unlock(&m);
}




int main(int argc, char const *argv[])
{
	flag = atoi(argv[1]);
	pthread_t t1,t2,t3,t4;
	n = 0;
	for(int i=0;i<4;i++) pthread_create(&t1,NULL,inc5,NULL);


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	printf("%d\n", n);

	return 0;
}