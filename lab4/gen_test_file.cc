#include <bits/stdc++.h>
using namespace std;

#define rn (double)rand()/(double)RAND_MAX

int main(int argc, char* argv[]){
	if(argc < 2){printf("usage: %s <no_of_intergers>\n",argv[0]); exit(1);}
	int n = atoi(argv[1]);
	FILE *fp = fopen("test","w");
	fprintf(fp, "%d\n",n);
	for(int i=0;i<n;i++) fprintf(fp, "%d\n", (int)(rn*100));
	fclose(fp);
	return 0;
}