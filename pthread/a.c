#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

using namespace std;
int n;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int flag;

void* inc10(void *a){
	printf("Inside inc10 \n");
	if(flag) pthread_mutex_lock(&m);
	int p = n;
	p++;
	n  = p;
	if(flag) pthread_mutex_unlock(&m);
}

void* inc5(void *a){
	printf("Inside inc5 \n");
	if(flag) pthread_mutex_lock(&m);
	int p = n;
	p++;
	sleep(2);
	n = p;
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
	pthread_create(&t1,NULL,inc5,NULL);
	pthread_create(&t2,NULL,inc10,NULL);
	pthread_create(&t3,NULL,inc15,NULL);
	pthread_create(&t4,NULL,inc20,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);

	printf("%d\n", n);

	return 0;
}