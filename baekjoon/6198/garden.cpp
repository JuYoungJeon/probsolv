#include<cstdio>
#include<stack>
using namespace std;
int b[80000];
stack<int> st;
int main(void){
	int n; 
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
	}
	st.push(b[0]);
	long long ans=0;
	for(int i=1;i<n; i++){
		while(!st.empty()&&b[i]>=st.top())
			st.pop();
		ans+=st.size();
		st.push(b[i]);
	}
	printf("%lld", ans);
}
