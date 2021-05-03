#include<cstdio>
#include<vector>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int sum=0;
	vector<int> a;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		if(t==0&&!a.empty()) a.pop_back();
		else if (t!=0){
			a.push_back(t);
		}
	}
	for(int i=0; i<a.size(); i++){
		sum+=a[i];
	}
	printf("%d", sum);
}
