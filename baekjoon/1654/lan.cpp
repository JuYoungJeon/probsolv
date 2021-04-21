#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long lan[10000];

int main(void){
	int n, k;
	long long sum=0;
	scanf("%d %d", &k, &n);
	for(int i=0; i<k; i++){
		scanf("%lld", &lan[i]);
		sum+=lan[i];
	}
	long long maxAns= sum/n;
	long long minAns=1;
	long long mid=maxAns;
	while(maxAns>=minAns){
		long long currAns=0;
		long long smallerAns=0;
		for(int i=0; i<k; i++){
			currAns+=lan[i]/mid;
			if(mid-1!=0)
				smallerAns+=lan[i]/(mid-1);
		}
		if(currAns<n)
			maxAns=mid-1;
		else if(currAns>n||(currAns==n&&smallerAns==n))
			minAns=mid+1;
		else
			break;
		mid=(maxAns+minAns)/2;
		if (mid==0) break;
	}
	cout << mid;
			
}
