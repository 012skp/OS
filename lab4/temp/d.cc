#include <bits/stdc++.h>

using namespace std;

int main(){
int flag = 0;
	
	if(flag){
			for(int i=0;i<=10;i++){
			char cmd[100];
			if(i == 0) sprintf(cmd,"./a %d > output",(int)pow(2,i));
			else sprintf(cmd,"./a %d >> output",(int)pow(2,i));
			system(cmd);
		}
		for(int i=0;i<=10;i++){
			char cmd[100];
			if(i == 0) sprintf(cmd,"./c %d > output1",(int)pow(2,i));
			else sprintf(cmd,"./c %d >> output1",(int)pow(2,i));
			system(cmd);
		}
	}
	else{
			for(int i=1;i<=20;i++){
			char cmd[100];
			if(i == 1) sprintf(cmd,"./a %d > output",i);
			else sprintf(cmd,"./a %d >> output",i);
			system(cmd);
		}
		for(int i=1;i<=20;i++){
			char cmd[100];
			if(i == 1) sprintf(cmd,"./c %d > output1",i);
			else sprintf(cmd,"./c %d >> output1",i);
			system(cmd);
		}
	}
	

}