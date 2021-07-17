#include<cstdio>
#include<vector>
using namespace std;
int win[1000001];
vector<int> psn;
int main(void){
	int TC;
	scanf("%d", &TC);
	int n=1;
	while(n*n<=1000001){
		psn.push_back(n*n);
		n+=1;
	}
	for(int i=1; i<=1000001; i++){
		bool kwin=false;
		for(auto& n: psn){
			if(n>i) break;
			if(win[i-n]%2==0) {kwin=true; break;}
		}
		if(kwin) win[i]=1;
		else win[i]=2;
	}
	for(int t=0; t<TC; t++){
		int tar;
		scanf("%d", &tar);
		if(win[tar]==1) printf("koosaga\n");
		else printf("cubelover\n");
	}
}
