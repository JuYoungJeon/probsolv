#include<iostream>
#include<string>
#include<cstring>
#include<vector>

#define BASE 200000
using namespace std;

int occ[100001];
int idx[400002];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	memset(occ, 0, sizeof(occ));
	memset(idx, -1, sizeof(idx));
	int ans=-1;
	int cnt=0;
	idx[BASE]=0;
	for(int i=1;i<=(int)s.size(); i++){
		if(s[i-1]=='S'){
			occ[i]=occ[i-1]+1;
			cnt+=2;
		}else if(s[i-1]=='K'){
			occ[i]=occ[i-1]+1;
			cnt-=1;
		}else{
			occ[i]=occ[i-1];
		}
		if(idx[cnt+BASE]==-1) idx[cnt+BASE]=i;
		else if(occ[i]-occ[idx[cnt+BASE]]>0) ans=max(ans, i-idx[cnt+BASE]);
	}
	cout << ((ans>0)? ans:-1);
}
