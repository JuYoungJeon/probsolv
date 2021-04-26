#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int n, k;
	cin >> n >> k;
	int numChar=1;
	long long minVal=1;
	long long maxVal=9;
	int targetNum=k;
	long long prevMax=0;
	while(1){
		if(k<maxVal) break;
		if(targetNum>(maxVal-minVal+1)*numChar)
			targetNum-=(maxVal-minVal+1)*numChar;
		else
			break;
		prevMax=maxVal;
		maxVal=1;
		for(int i=1; i<=numChar; i++)
			maxVal+=pow(10, i);
		maxVal*=9;
		minVal=pow(10, numChar);
		numChar+=1;
	}
	long long number= targetNum/numChar+prevMax;
	long long remainder=targetNum%numChar;

	if(number > n) cout << "-1"; 
	if(remainder>0) {
		if(number == n) cout << "-1"; 
		else{
			number+=1;
			cout << to_string(number)[remainder-1];
		}
	}else{
		cout << to_string(number)[numChar-1];
	}

}
