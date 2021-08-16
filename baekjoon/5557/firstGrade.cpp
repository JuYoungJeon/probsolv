#include<cstdio>
#define ll long long
using namespace std;

ll dp[100][21];
int arr[100];
int n;
int main(void){
	scanf("%d", &n);
	for(int i=0;i<n-1; i++){
		scanf("%d", &arr[i]);
	}
	int eq;
	scanf("%d", &eq);
	dp[0][arr[0]]=1;
	for(int i=1; i<n-1; i++){
		for(int j=0; j<=20; j++){
			if(dp[i-1][j]>0){
				if(j+arr[i]>=0&&j+arr[i]<=20) dp[i][j+arr[i]]+=dp[i-1][j];
				if(j-arr[i]>=0&&j-arr[i]<=20) dp[i][j-arr[i]]+=dp[i-1][j];
			}
		}
	}
	printf("%lld", dp[n-2][eq]);
}
