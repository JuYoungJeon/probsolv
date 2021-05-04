#include<cstdio>
#include<queue>
using namespace std;
int main(void){
	queue<int> q;
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	int i=1;
	int ans;
	while(!q.empty()){
		int next=q.front();
		q.pop();
		if(i%2==0){q.push(next);}
		i++;
		ans=next;
	}
	printf("%d", ans);
}
