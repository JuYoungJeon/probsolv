#include<cstdio>
#include<vector>
using namespace std;
const int MAX_VAL=360000;
int clockA[MAX_VAL*2];
int clockB[MAX_VAL];

vector<int> pi;
void kmp(){
	int j=0;
	pi.resize(MAX_VAL, 0);
	for(int i=1; i<MAX_VAL;i++){
		while(j>0&&clockB[i]!=clockB[j]){
			j=pi[j-1];
		}
		if(clockB[i]==clockB[j]){
			pi[i]=j+1;
			j+=1;
		}
	}
}

bool compStr(){
	int j=0;
	for(int i=0;i<MAX_VAL*2; i++){
		while(j>0&&clockA[i]!=clockB[j]){
			j=pi[j-1];
		}
		if(clockA[i]==clockB[j]){
			if(j==MAX_VAL-1) return true;
			else j+=1;
		}
	}
	return false;
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n; i++){
		int at;
		scanf("%d", &at);
		clockA[at]=1;
		clockA[at+MAX_VAL]=1;
	}
	for(int i=0;i<n; i++){
		int bt;
		scanf("%d", &bt);
		clockB[bt]=1;
	}
	kmp();
	bool ans = compStr();
	if (ans) printf("possible");
	else printf("impossible");
}
