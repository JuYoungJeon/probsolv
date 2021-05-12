#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	vector<int> num;
	for(int i=0;i<n ;i++){
		int t;
		scanf("%d", &t);
		num.push_back(t);
	}
	int x;
	scanf("%d", &x);
	sort(num.begin(), num.end());
	int ans=0;
	int s=0, e=n-1;
	while(s<e){
		int sum=num[s]+num[e];
		if(sum==x) {s+=1; e-=1;ans+=1;}
		else if(sum>x)e-=1;
		else s+=1;
	}
	printf("%d", ans);
}
//Array로하면 timeout vector로 하면 correct(sort bottleneck)
