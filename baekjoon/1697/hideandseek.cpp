#include<cstdio>
#include<queue>
using namespace std;

int timestamp[200000];
queue<int> q;
int move(int c, int k){
	if(c==k) return 0;
	q.push(c);
	timestamp[c]=0;
	int topBound=c<k? k: c;
	topBound*=2;
	while(!q.empty()){
		int next = q.front();
		q.pop();
		for(int i=0; i<3; i++){
			int nx;
			if(i==0)
				nx=next+1;
			if(i==1)
				nx=next-1;
			if(i==2)
				nx=2*next;
			if(nx>=0&&nx<=topBound){
				if(!timestamp[nx]||timestamp[nx]>timestamp[next]+1){
					timestamp[nx]=timestamp[next]+1;
					q.push(nx);
				}
			}
		}
	}
	return timestamp[k];
}

int main(void){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d",move(n, k));
}
//Note Range check 내가 설정 한 값이 max min 이아닐수도 있구 배열 크기도 조정
