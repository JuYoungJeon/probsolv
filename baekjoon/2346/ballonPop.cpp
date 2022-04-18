#include<iostream>

using namespace std;
int ballon[1000];
int check[1000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N; 
	for(int i =0;i<N; i++){
		cin >> ballon[i];
	}
	int cur =0;
	cout << cur +1<<' ';
	check[cur]=1;
	for(int i=1;i<N; i++){
		int m = ballon[cur];
		int cnt =0;
		if(m<0){
			while(cnt>m){
				do{
					cur--;
					if(cur==-1) cur=N-1;
				}while(check[cur]);
				cnt--;
			}
		}else{
			while(cnt<m){
				do{
					cur++;
					if(cur==N) cur=0;
				}while(check[cur]);
				cnt++;
			}
		}
		check[cur]=1;
		cout << cur+1 <<' ';
	}
}
