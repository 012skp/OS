#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;



void scanline(char str[]){
int i=0;
char ch;
while( (ch = getchar()) != '\n') {str[i] = ch; i++;}
str[i] = '\0';

}



bool redirection(char buff[]){
	for(int i=0;i<strlen(buff);i++){
		if(buff[i] == '>' || buff[i] == '>') return 1;
	}
	return 0;
}


bool background(char str[]){

for(int i=0;i<strlen(str);i++) if(str[i] == '&') return 1;
return 0;

}

int main(){
	char buff[100];
	char pwd[100];
	getcwd(pwd,sizeof(pwd));
        char str[300];
	while(1){
		printf("%s>",pwd); fflush(stdout);
		scanline(buff); //printf("buff: %s\n",buff);
		if(!strncmp(buff,"cd ",3)){
			chdir(buff+3);
                        getcwd(pwd,sizeof(pwd));
		}
		else if(redirection(buff)) system(buff);
		else if(background(buff)){
			int pid = fork();
			if(pid == 0){
				system(buff);
				exit(1);
			}

		}
		else{
			FILE *fp = popen(buff,"r");
			if(fp == NULL){ printf("%s failed..\n",buff); exit(1);}
			while(!feof(fp)){
				bzero(str,256);
				fread(str,256,1,fp);
				str[256] = '\0';
				printf("%s",str);
			}
			fflush(stdout); printf("\n");
			pclose(fp);
		}
	}


return 0;
}

























