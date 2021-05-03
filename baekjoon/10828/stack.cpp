#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(void){
	int numCmd;
	cin>> numCmd;
	vector<int> t;
	for(int i=0; i<numCmd; i++){
		string c;
		cin>>c;
		if(c=="push"){
			int num;
			cin >> num;
			t.push_back(num);
		}
		if(c=="pop"){
			if(t.empty()) {cout << "-1\n"; continue;}
			cout << t.back()<<'\n';
			t.pop_back();
		}
		if(c=="top"){
			if(t.empty()) {cout << "-1\n"; continue;}
			cout << t.back()<<'\n';
		}
		if(c=="size"){
			cout << t.size()<<'\n';
		}
		if(c=="empty"){
			cout<< t.empty()<<'\n';
		}
	}
}
