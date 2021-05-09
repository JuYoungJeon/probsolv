#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
struct cmp{
	bool operator()(int a, int b){
		if(abs(a) == abs(b)) return a>b;
		else return abs(a)>abs(b);
	}
};
int main(void){
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, cmp> pq;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		if(t!=0) pq.push(t);
		else{
			if(pq.empty())printf("0\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
}
