#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
pair<int, int> dp[10][3];
int arr[10][3];

int main(void){
	int n;
	scanf("%d", &n);
	scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);
	for(int i=0; i<3; i++) dp[0][i]=make_pair(arr[0][i], arr[0][i]);
	int finalIdx=0;
	for(int i=1; i<n; i++){
		scanf("%d %d %d", &arr[i%10][0], &arr[i%10][1], &arr[i%10][2]);
		for(int j=0; j<3; j++){
			int p;
			if(i%10-1<0) p=9;
			else p=i%10-1;
			int prevMin=dp[p][j].first;
			int prevMax=dp[p][j].second;
			for(int k=-1; k<2; k++){
				if(j+k<0||j+k>2) continue;
				prevMin=min(prevMin, dp[p][j+k].first);
				prevMax=max(prevMax, dp[p][j+k].second);
			}
			dp[i%10][j]=make_pair(prevMin+arr[i%10][j], prevMax+arr[i%10][j]);
			finalIdx=i%10;
		}
	}
	int ansMax=dp[finalIdx][0].second, ansMin=dp[finalIdx][0].first;
	for(int i=1; i<3; i++){
		ansMax=max(dp[finalIdx][i].second, ansMax);
		ansMin=min(dp[finalIdx][i].first, ansMin);
	}
	printf("%d %d", ansMax, ansMin);
}
