#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>


#define pb push_back
using namespace std;


int n; //no of elements in array...
int cnt;// count of 3s.....
vector<int> a;
struct se
{
	int start;
	int end;
};
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* count3(void *s){
	struct se ss = *(struct se*)s;
	//printf("inside this thread start = %d end = %d\n",ss.start,ss.end);
	for(int i=ss.start;i<=ss.end;i++){
		if(a[i] == 3){
			pthread_mutex_lock(&lock);
			cnt++;
			pthread_mutex_unlock(&lock);
		}
	}
}


int main(int argc, char* argv[]){
	if(argc < 2){printf("usage %s <no_of_threads>\n",argv[0]); exit(1);}
	int no_of_threads = atoi(argv[1]);
	cnt = 0;
	struct timeval t1,t2,t3,t4,t5,t6;
	gettimeofday(&t1,NULL);
	FILE *fp = fopen("test","r");
	fscanf(fp,"%d",&n);
	//cout<<"size  = "<<n<<endl;
	vector<pthread_t> tid(n);
	int t;
	for(int i=0;i<n;i++){ fscanf(fp,"%d",&t); a.pb(t); }
	fclose(fp);
	if(argc == 3){ // debugin mode....
		int ccc = 0;
		for(int i=0;i<n;i++) if(a[i] == 3) ccc++;
		printf("count = %d\n", ccc);
		exit(1);
	}
	gettimeofday(&t2,NULL);
	vector<struct se> s(n);
	s[0].start = 0;
	for(int i=1; i<=no_of_threads; i++){
		s[i-1].end = ceil(((double)n/(double)no_of_threads)*i);
		pthread_create(&tid[i-1],NULL,count3,(void*)&s[i-1]);
		if(i != no_of_threads) s[i].start = s[i-1].end + 1;
	}
	// join all threads....
	for(int i=0;i<no_of_threads;i++) pthread_join(tid[i],NULL);
	gettimeofday(&t3,NULL);
	timersub(&t2,&t1,&t4); // readtime....
	timersub(&t3,&t2,&t5); // counttime....
	timersub(&t3,&t1,&t6); //overall time...
	//printf("readtime = %ld sec %ld usec \n",t4.tv_sec,t4.tv_usec);
	printf("%d\t%ld \n",no_of_threads, t5.tv_usec);
	//printf("overall time = %ld sec %ld usec \n",t6.tv_sec,t6.tv_usec);
	//printf("total count  =   %d\n", cnt );
	return 0;
}