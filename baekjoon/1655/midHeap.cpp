#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int> > l;
	priority_queue<int, vector<int>, less<int> > s;
	int mid;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		if(i==0) mid=t;
		else{
			if(mid<t){
				if(l.size()==s.size()) {
					l.push(t);
				}else{
					s.push(mid);
					l.push(t);
					mid=l.top();
					l.pop();
				}
			}else if(mid>t){
				if(s.size()==l.size()-1) {
					s.push(t);
				}else {
					l.push(mid);
					s.push(t);
					mid=s.top();
					s.pop();
				}
			}else{
				if(s.size()==l.size()) l.push(t);
				else s.push(t);
			}
		}
		printf("%d\n", mid);
	}

}
