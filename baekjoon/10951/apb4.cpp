#include<cstdio>
using namespace std;

int main(void){
	int a, b;
	while(scanf("%d %d", &a, &b)!=EOF){
		printf("%d\n", a+b);
	}
}

//EOF checking : cin >> a>>b; while(cin.eof()){}
//while(scanf("%d %d", &a, &b)!=EOF){}
