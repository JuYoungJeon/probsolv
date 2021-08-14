#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int dp[100001];
int bt[100001];

int main(void){
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	memset(bt, -1, sizeof(bt));
	dp[1]=0;
	for(int i=1; i<=N; i++){
		vector<int> div;
		for(int j=1;j*j<=i; j++){
			if(i%j==0){
				div.push_back(j);
				if(j != i/j ) div.push_back(i/j);
			}
		}
		for(int d: div){
			if(i+d>N) continue;
			if(dp[i+d]==(dp[i]+1)%2) continue;
			if(bt[i]==-1) bt[i]=i;
			if(dp[i+d]==-1){
				dp[i+d]=(dp[i]+1)%2;
			}else if(dp[i+d]!=(dp[i]+1)%2){
				if(bt[i]!=i&&bt[i+d]>bt[i]){
					dp[i+d]=(dp[i]+1)%2;
					bt[i+d]=bt[i];
				}
			}else{
				bt[i+d]=min(bt[i+d], bt[i]);
			}
		}
	}
	if(dp[N]) printf("Kali");
	else printf("Ringo");
}
