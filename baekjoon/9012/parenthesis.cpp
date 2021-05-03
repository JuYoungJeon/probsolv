#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		string a;
		cin >> a;
		int cnt=0;
		bool end=false;
		for(int j=a.size()-1; j>=0; j--){
			if(a[j]==')')cnt++;
			else{
				if(cnt==0) {cout<<"NO\n"; end=true; break;}
				else cnt--;
			}
		}
		if(end) continue;
		if(cnt==0) cout<< "YES\n";
		else cout << "NO\n";
	}
}

