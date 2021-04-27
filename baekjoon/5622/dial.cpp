#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
int pn[26]={2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

int main(void){
	char in[15];
	scanf("%s", in);
	int sec=0;
	for(int i=0; i<strlen(in); i++){
		sec+=(pn[in[i]-'A']-1)+2;
	}
	printf("%d", sec);
}
