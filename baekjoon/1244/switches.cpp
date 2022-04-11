#include<iostream>

using namespace std;

int switches[101];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for(int i=1;i<=N; i++){
		cin >> switches[i];
	}
	int stu;
	cin >> stu;
	for(int i=0;i<stu; i++){
		int s, idx;
		cin >> s>>idx;
		if(s==1){
			int t=1;
			while(idx*t<=N){
				switches[idx*t]=!switches[idx*t];
				t++;
			}
		}else {
			int t=1;
			switches[idx]=!switches[idx];
			while(idx-t>0&&idx+t<=N&&switches[idx-t]==switches[idx+t]){
				switches[idx-t]=!switches[idx-t];
				switches[idx+t]=!switches[idx+t];
				t+=1;
			}
		}
	}
	for(int i=1; i<=N; i++){
		cout << switches[i]<<' ';
		if(i%20==0)cout <<'\n';
	}
}
