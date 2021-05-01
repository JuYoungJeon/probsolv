#include<cstdio>
#include<vector>
using namespace std;
int numOp[4];
vector<int> operands;
int minV, maxV;
void insertOperator(int n, int sel, int curVal){
	if(sel==n-1) {
		maxV=maxV<curVal?curVal:maxV;
		minV=minV>curVal?curVal:minV;
		return;
	}
	for(int i=0; i<4; i++){
		if(!numOp[i]) continue;
		int before=curVal;
		if(i==0) curVal+=operands[sel+1];
		else if(i==1) curVal-=operands[sel+1];
		else if(i==2) curVal*=operands[sel+1];
		else if(i==3) curVal/=operands[sel+1];
		numOp[i]--;
		insertOperator(n, sel+1, curVal);
		numOp[i]++;
		curVal=before;
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	minV=1000000000, maxV=-1000000000;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		operands.push_back(t);
	}
	for(int i=0; i<4; i++)
		scanf("%d", &numOp[i]);
	insertOperator(n, 0, operands[0]);
	printf("%d\n%d", maxV, minV);
}
//Min, max init 값 설정 확인, negative num 올수 있기때문에 max값은 negative max를 설정
