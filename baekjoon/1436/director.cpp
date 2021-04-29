#include<cstdio>
#include<string>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int it=666;
	int ith=1;
	while(ith<n){
		it++;
		while(to_string(it).find("666")==string::npos) it++;
		ith+=1;
	}
	printf("%d", it);
}
