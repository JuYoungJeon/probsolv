#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

long long d[101];
int m[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
queue<int> q;

void getMin(int n){
	if(d[n]!=0) return;
	q.push(0);
	int a=1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		if(t!=0&&d[t]==0) {
			q.push(a); a+=1;
			continue;
		}
		if(t==n) break;
		for(int i=0; i<10; i++){
			if(d[t+m[i]]==0) {
				if(t==0&&i==0) d[t+m[i]]=6;
				else d[t+m[i]]=d[t]*10+i;
			}
			else d[t+m[i]]=min(d[t+m[i]], d[t]*10+i);
		}
		q.push(a);
		a+=1;
	}
}

int main(void){
	int tc;
	scanf("%d", &tc);
	memset(d,0, sizeof(d));
	d[0]=0;
	int maxNum=0;
	int num[101];
	for(int i=0; i<tc; i++){
		scanf("%d", &num[i]);
		if (num[i]>maxNum) maxNum=num[i];
	}
	getMin(maxNum);
	for(int i=0; i<tc; i++){
		string maxval="";
		int maxMatch=num[i];
		if(num[i]%2!=0){
			maxMatch-=3;
			maxval+="7";
		}
		while(maxMatch>0){
			maxMatch-=2;
			maxval+="1";
		}

		printf("%lld %s\n", d[num[i]], maxval.c_str());
	}
	
}
