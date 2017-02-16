#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
	if(argc<2){printf("usage %s <size_of_data>\n",argv[0]); exit(1);}
	FILE *fp = fopen("test","w");
	int n = atoi(argv[1]);
	fprintf(fp, "%d\n",n);
	for(int i=0;i<n;i++){
		fprintf(fp, "%d\n", rand()%100);
	}
	fclose(fp);

	return 0;
}