#include<cstdio>
#include<string>
using namespace std;
int main(void){
	char t[101];
	scanf("%s", t);
	string s=t;
	int l, r;
	l=s.size()/2-1;
	if(s.size()%2==0) {r=s.size()/2;}
	else {r=s.size()/2+1;} 
	bool ret=true;
	while(l>=0){
		if(s[l]!=s[r]){ret=false; break;}
		r+=1; l-=1;
	}
	printf("%d", ret);
}
