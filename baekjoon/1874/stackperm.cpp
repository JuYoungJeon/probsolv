#include<cstdio>
#include<vector>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	vector<int> stack;
	vector<char> ans;
	vector<int> target;
	bool succ=true;
	int num=1;
	for(int i=0; i<n; i++){
		int tar;
		scanf("%d", &tar);
		target.push_back(tar);
	}
	for(int i=0; i<n; i++){
		while(target[i]>=num){
			stack.push_back(num); num+=1;
			ans.push_back('+');
		}
		int out=stack.back();
		if(out!=target[i]){
			succ=false;
			break;
		}
		stack.pop_back();
		ans.push_back('-');
	}
	if(succ){
		for(int i=0; i<ans.size(); i++)
			printf("%c\n", ans[i]);
	}else
		printf("NO");
}

