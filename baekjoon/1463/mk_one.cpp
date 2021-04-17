#include <iostream>
#include <algorithm>

using namespace std;

int cache[1000000];

int getMinMove(int n){
	if (n==1)return 0;
	int minVal;
	if(cache[n-1]!=0){
		minVal=cache[n-1]+1;
	}else{
		minVal=getMinMove(n-1)+1;
	}
	if (n%3==0){
		if(cache[n/3]!=0){
			minVal=min(minVal, cache[n/3]+1);
		}else{
			minVal=min(minVal, getMinMove(n/3)+1);
		}
	}
	if(n%2==0){
		if(cache[n/2]!=0){
			minVal=min(minVal, cache[n/2]+1);
		}else{
			minVal=min(minVal, getMinMove(n/2)+1);
		}
	}
	return minVal;
}

int main(){
	int n;
	cin >> n;
	cout << getMinMove(n);
}
