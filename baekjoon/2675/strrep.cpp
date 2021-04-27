#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main(void){
	int tc;
	scanf("%d", &tc);
	for(int t=0; t < tc; t++){
		int n;
		char c[20];
		scanf("%d", &n);
		scanf("%s", c);
		for(int i=0; i<strlen(c); i++)
			for(int j=0; j<n; j++)
				printf("%c", c[i]);
		cout << '\n';
	}
}
