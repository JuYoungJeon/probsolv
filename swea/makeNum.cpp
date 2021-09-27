#include<iostream>
using namespace std;
int numOp[4];
int arr[12];
int maxval, minval;
void dfs(int N, int opidx, int numidx, int curNum){
	if(numidx==N){
		maxval=max(maxval, curNum);
		minval=min(minval, curNum);
		return;
	}
	if(!numOp[opidx]) return;
	numOp[opidx]--;
	int newNum;
	if(opidx==0) newNum=curNum+arr[numidx];
	else if(opidx==1) newNum=curNum-arr[numidx];
	else if(opidx==2) newNum=curNum*arr[numidx];
	else newNum=curNum/arr[numidx];
	for(int i=0;i<4; i++)
		dfs(N, i, numidx+1, newNum);
	numOp[opidx]++;
	return ;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T; 
	for(int test_case=1; test_case<=T; test_case+=1){
		int N;
		cin >> N;
		for(int i=0;i<4; i++) cin >> numOp[i];
		for(int i=0;i<N; i++) cin >> arr[i];
		maxval=-100000001;
		minval=100000001;
		for(int i=0;i<4; i++){
			dfs(N, i, 1,arr[0]);
		}
		cout <<'#'<<test_case<<' '<< maxval-minval<<'\n';
	}
}
