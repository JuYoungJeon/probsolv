#include<cstdio>
#include<queue>
using namespace std;
int main(void){
	int n;
	priority_queue<int> pq;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		if(t!=0)
			pq.push(t);
		else{
			if(pq.empty()){printf("0\n"); continue;}
			printf("%d\n", pq.top());
			pq.pop();
		}
	}
}
