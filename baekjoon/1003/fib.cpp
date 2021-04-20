#include <iostream>
#include <cstring>
using namespace std;

int fib[41][2];

void fib_f(int n){
	if(n==0){
		fib[0][0]=1;
		return ;}
	if(n==1){
		fib[1][1]=1;
		return ;
	}
	if(fib[n-1][0]==0&&fib[n-1][1]==0)
		fib_f(n-1);
	if(fib[n-2][0]==0&&fib[n-2][1]==0)
		fib_f(n-2);

	fib[n][0]=fib[n-1][0]+fib[n-2][0];
	fib[n][1]=fib[n-1][1]+fib[n-2][1];
}

int main(){
	int tc;
	cin >> tc; 

	fib_f(40);
	for(int i=0; i<tc; i++){
		int n; 
		cin >> n;

		cout << fib[n][0]<< ' '<<fib[n][1] << '\n';
	}

}

