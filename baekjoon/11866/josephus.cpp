#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int main(void){
	int n, k;
	queue<int> q;
	vector<int> ans;
	scanf("%d %d",&n, &k);
	for(int i=1; i<=n; i++)
		q.push(i);
	int i=1;
	while(!q.empty()){
		int next=q.front();
		q.pop();
		if(i%k!=0) q.push(next);
		else ans.push_back(next);
		i++;
	}
	printf("<");
	for(int j=0; j<ans.size(); j++){
		printf("%d", ans[j]);
		if(j!=ans.size()-1) printf(", ");
		else printf(">");
	}
}
