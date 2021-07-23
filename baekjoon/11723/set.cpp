#include<iostream>
using namespace std;
int arr[21];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> m;
	for(int i=0;i<m; i++){
		string cmd;
		cin >> cmd;
		if(cmd!="all"&&cmd!="empty"){
			int num;
			cin >> num;
			if(cmd=="add"){
				arr[num]=1;
			}else if(cmd=="remove"){
				arr[num]=0;
			}else if(cmd=="check"){
				cout<<arr[num]<<'\n';
			}else if(cmd=="toggle"){
				if(arr[num]) arr[num]=0;
				else arr[num]=1;
			}
		}else if(cmd=="all"){
			for(int j=1; j<=20; j++) arr[j]=1;
		}else if (cmd=="empty"){
			for(int j=1;j<=20; j++) arr[j]=0;
		}
		cin.clear();
	}
}
