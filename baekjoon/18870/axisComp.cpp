#include<cstdio>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	vector<int> num;
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		num.push_back(t);
	}
	vector<int> original=num;
	sort(num.begin(), num.end());
	map<int, int> num2comp;
	int sum=0;
	for(int i=0; i<n; i++){
		if(i==0 || num[i]!=num[i-1]) {num2comp[num[i]]=sum; sum+=1;}
	}
	for(int i=0; i<n; i++)
		printf("%d ", num2comp[original[i]]);
}
