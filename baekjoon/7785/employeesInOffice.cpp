#include<map>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	map<string, int> records;
	cin >> N;
	for(int i=0;i<N; i++){
		string name, rec;
		cin >> name >> rec;
		if(rec=="enter") records[name]=1;
		else records[name]=0;
	}
	for(auto it = records.rbegin(); it!=records.rend(); it++){
		if(it->second==1) cout << it->first<<'\n';
	}
}
