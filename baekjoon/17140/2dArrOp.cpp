#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define pii pair<int, int>

vector<pii> sortedA[101];
int cntarr[101][101];
int arr[101][101];

bool cmp(pii a, pii b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
int main(void){
	int r, c, k;
	scanf("%d %d %d", &r, &c, &k);
	for(int i=1; i<=3; i++){
		for(int j=1;j<=3; j++){
			scanf("%d", &arr[i][j]);
			cntarr[i][arr[i][j]]+=1;
		}
	}
	int nc=3, nr=3;
	int ans=0;
	while(arr[r][c]!=k&&ans<=100){
		ans+=1;
		int n = nr>=nc? nr:nc;
		for(int i=1; i<=n; i++){
			sortedA[i].clear();
			for(int j=1; j<=100; j++){
				if(cntarr[i][j]==0) continue;
				sortedA[i].push_back({j, cntarr[i][j]});
			}
			sort(sortedA[i].begin(), sortedA[i].end(), cmp);
		}
		int it=0;
		memset(cntarr, 0, sizeof(cntarr));
		memset(arr, 0, sizeof(arr));
		for(int i=1;i<=n; i++){
			int nit=1;
			for(auto &e: sortedA[i]){
				if(nit>100) break;
				if(nr>=nc){
					arr[i][nit++]=e.first;
					if(nit>100) break;
					arr[i][nit++]=e.second;
				}else{
					arr[nit++][i]=e.first;
					if(nit>100) break;
					arr[nit++][i]=e.second;
				}
			}
			it=max(it, nit-1);
		}
		if(nr>=nc) nc=it;
		else nr=it;
		if(nr>=nc){
			for(int i=1; i<=nr; i++){
				for(int j=1; j<=nc; j++){
					cntarr[i][arr[i][j]]+=1;
				}
			}
		}else{
			for(int i=1; i<=nc; i++){
				for(int j=1; j<=nr; j++){
					cntarr[i][arr[j][i]]+=1;
				}
			}
		}
	}
	if(ans>100)printf("-1");
	else printf("%d", ans);
}
