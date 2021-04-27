#include <cstring>
#include <cctype>
#include <string>
#include <cstdio>

using namespace std;

int main(void){
	char s[1000001];
	scanf("%s", s);
	int al[26]={0,};
	string st=s;
	for(int i=0; i<st.size(); i++){
		if(st[i]>='A'&&st[i]<='Z') st[i]=st[i]-('Z'-'z');
		al[st[i]-'a']+=1;
	}
	char ans;
	int maxV=0;
	for(int i=0; i<26; i++){
		if(al[i]>maxV) {maxV=al[i]; ans='a'+i;;continue;}
		if(al[i]==maxV) {ans='?';}

	}
	if(ans!='?')
		printf("%c", toupper(ans));
	else
		printf("%c", ans);
}
//Note: 변수 초기화를 생활화하자!
