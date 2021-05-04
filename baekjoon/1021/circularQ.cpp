#include<cstdio>
#include<deque>
using namespace std;
int main(void){
	int n,m;
	scanf("%d %d", &n, &m);
	int num[50];
	deque<int> cq;
	for(int i=0; i<m; i++){
		int t;
		scanf("%d", &num[i]);
	}
	for(int i=1; i<=n; i++)
		cq.push_back(i);
	int ans=0;
	for(int i=0; i<m; i++){
		deque<int> p=cq;
		deque<int> q=cq;
		int less=50;
		int cnt=0;
		while(p.front()!=num[i]){
			p.push_back(p.front());
			p.pop_front();
			cnt+=1;
		}
		less=cnt;
		p.pop_front();
		cq=p;
		cnt=0;
		while(q.front()!=num[i]){
			q.push_front(q.back());
			q.pop_back();
			cnt+=1;
		}
		q.pop_front();
		if(less>cnt){
			less=cnt;
			cq=q;
		}
		ans+=less;
	}
	printf("%d",ans);
}
