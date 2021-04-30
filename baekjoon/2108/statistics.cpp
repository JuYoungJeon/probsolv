#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int nu[500000];
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &nu[i]);
	sort(nu, nu+n);
	int sum=0;
	int medium=nu[n/2];
	int freq=0; 
	vector<int> freqN; 
	int range=nu[n-1]-nu[0];
	int count=1;
	for(int i=0; i<n; i++){
		sum+=nu[i];
		if(i!=0&&nu[i-1]==nu[i]) count+=1;
		else count=1;
		if(count>= freq){
			if(count!=freq){ 
				freqN.clear();
			}
			freq=count;
			freqN.push_back(nu[i]);
		}
	}
	sum=floor(sum/(n*1.0)+0.5);
	int fans= freqN.size()>1? freqN[1]:freqN[0];
	printf("%d\n%d\n%d\n%d", sum, medium, fans, range);
}
//Note: 문제잘읽기
	
