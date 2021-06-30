#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int per[8];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &per[i]);
	}
	int ans=0;
	vector<int> perm;
	for(int i=0; i<n; i++) perm.push_back(per[i]);
	sort(perm.begin(), perm.end());
	do{
		int cnt=0;
		for(int i=0; i<n; i++){
			int j=i+1;
			int sum=perm[i];
			while(sum<=50&&j<n){
				if(sum==50)cnt+=1;
				sum+=perm[j];
				j+=1;
			}
		}
		ans=max(cnt, ans);
	}while(next_permutation(perm.begin(), perm.end()));
	printf("%d", ans);
}
