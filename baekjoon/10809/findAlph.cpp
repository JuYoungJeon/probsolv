#include <cstdio>
#include <cstring>
int main(void){
	char s[100];
	int alph[26];
	memset(alph, -1, sizeof(alph));
	scanf("%s", s);
	for(int i=0; i<strlen(s); i++){
		if (alph[s[i]-'a']==-1) alph[s[i]-'a']=i;}
	for(int i=0; i<26; i++)
		printf("%d ", alph[i]);
}
//scanf 는 char에 대해서만 (string 안됨) 
//string 받으려면 char로 받은다음에 st=ch;해주어야 함

