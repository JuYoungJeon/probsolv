#include<cstdio>
#include<cstring>
int d[21][21][21];
int w(int a, int b, int c){
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20||b>20||c>20) return w(20, 20, 20);
	if(d[a][b][c]) return d[a][b][c];
	if(a<b && b<c){
		d[a][b][c]=w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);
		return d[a][b][c];
	}
	d[a][b][c]=w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);
	return d[a][b][c];
}
int main(void){
	memset(d, 0, sizeof(d)); 
	d[0][0][0]=1;
	while(1){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==-1&&b==-1&&c==-1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}
