#include<bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;
#define pb push_back

vector<sem_t> s;
vector<int> status;
vector<pthread_mutex_t> lock;
typedef vector<vector<int> > graph;
graph g,gi;




void* do_it(void *arg){
	int node_id = *(int*)arg;
	printf("Process %d is ready\n",node_id);
  while(status[node_id]) sem_wait(&s[node_id]);

  printf("Process %d started executing\n",node_id);
  sleep(rand()%10);
  printf("Process %d terminated\n",node_id);

  //Signal child process if waiting...
  for(int i=0;i<g[node_id].size();i++){
	int nn = g[node_id][i];
  pthread_mutex_lock(&lock[nn]);
  	status[nn]--;
    sem_post(&s[nn]);
  pthread_mutex_unlock(&lock[nn]);
  }

}



int main(){
  FILE *fp = fopen("input","r");
  int n;
  fscanf(fp,"%d\n",&n);
  g.resize(n+1),gi.resize(n+1);
  s.resize(n+1);
  lock.resize(n+1);
  status.resize(n+1);

  while(!feof(fp)){
    int u,v;
    fscanf(fp,"%d,%d\n",&u,&v);
    g[u].pb(v);
    gi[v].pb(u);
  }
  for(int i=1;i<=n;i++) status[i] = 0;
  for(int i=1;i<=n;i++) status[i] = gi[i].size();
  for(int i=1;i<=n;i++) if (sem_init(&s[i], 0, 0) == -1) printf("sem_init: failed: %s\n", strerror(errno));
	
  //Creating Threads...
  pthread_t t[n];
  int node_id[n+1];
  for(int i=1;i<=n;i++) node_id[i] = i;
  for(int i=1;i<=n;i++) pthread_create(&t[i-1],NULL,do_it,(void*)&node_id[i]);
  for(int i=1;i<=n;i++) pthread_join(t[i-1],NULL);



}
