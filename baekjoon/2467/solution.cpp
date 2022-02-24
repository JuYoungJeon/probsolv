#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> arr;
	cin >> N;
	for(int i=0;i<N; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	if(arr.size()==2) {
		cout << arr.front() <<' '<<arr.back();
		return 0;
	}
	int aa, ab;
	aa= 0; ab=N-1;
	int a = aa;
	int b = ab;
	while(a<b){

		if(abs(arr[b]+arr[a+1])<abs(arr[b-1]+arr[a])){
			a=a+1;
		}else {
			b=b-1;
		}
		if(a>=b) break;
		if(abs(arr[ab]+arr[aa])>abs(arr[b]+arr[a])){
			aa=a;
			ab=b;
		}
	}
	cout << arr[aa] << ' '<<arr[ab];
}
