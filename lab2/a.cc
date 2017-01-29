#include<bits/stdc++.h>
using namespace std;
#include<unistd.h>
int f(int n){
	usleep(1); // sleeps for 1000 micro seconds....
	cout<<"n = "<<n<<endl;
	if(n == 0) return 0;
	return f(n-1);
}

int main(){
int n = 1000000;
cout<<f(n);



return 0;
}
