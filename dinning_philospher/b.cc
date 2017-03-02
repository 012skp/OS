#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


using namespace std;
#define UNIT_TIME 100000
#define rn (double)rand()/(double)RAND_MAX


sem_t s[5];
int states[5]; // thinking 0, hungry 1 eating 2;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void test(int n){
	int next = (n+1)%5;
	int prev = (n+4)%5;
	pthread_mutex_lock(&lock);
	if(states[next] != 2 && states[prev] != 2){
		states[n] = 2; // state eating...
		sem_post(s+n);
	}
	pthread_mutex_unlock(&lock);
}

int pickup(int n){
	states[n] = 1; // Philospher hungry...
	test(n);
	if(states[n] != 2){
		sem_wait(s+n);
	}
}

void putdown(int n){
	states[n] = 0; // Philospher thinking...
	int next = (n+1)%5;
	int prev = (n+4)%5;
	test(next);
	test(prev);
}





void* do_it(void *arg){
	int ph_id = *(int*)arg;
	int r;
	while(1){
		states[ph_id] = 0; // Philospher t
		printf("Philospher %d thinking...\n",ph_id);
		r = rn*30*UNIT_TIME;
		usleep(r); //sleeps for 30 units of time...


		// Philospher Hungry...
		printf("Philospher %d Hungry.....\n",ph_id );
		pickup(ph_id);
		// Philospher Eating...
		printf("Philospher %d eating....\n", ph_id);
		r = rn*10*UNIT_TIME;
		usleep(r);

		putdown(ph_id);
	}
	

}

int main(){
	
	pthread_t t[5];
	int ph_id[5];
	for(int i=0;i<5;i++){ //initialse semaphores...
		if (sem_init(s+i, 0, 0) == -1) printf("sem_init: failed: %s\n", strerror(errno));
	}
	for(int i=0;i<5;i++) ph_id[i] = i;
	for(int i=0;i<5;i++) pthread_create(t+i,NULL,do_it,(void*)&ph_id[i]);

	for(int i=0;i<5;i++) pthread_join(t[i],NULL);

	return 0;
}