#include<cstdio>
#include<vector>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	vector<int> stack;
	for(int i=0; i<n; i++){
		int d;
		scanf("%d", &d);
		stack.push_back(d);
	}
	vector<int> target;
	vector<int> ans;
	for(int i=n-1; i>=0; i--){
		if(target.empty()){
			ans.push_back(-1);
			target.push_back(stack[i]);
			continue;
		}
		while(!target.empty()&&target.back()<=stack[i]){ target.pop_back();}
		if(target.empty()) ans.push_back(-1);
		else ans.push_back(target.back());
		target.push_back(stack[i]);
	}
	for(int i=ans.size()-1; i>=0; i--)
		printf("%d ", ans[i]);
}
