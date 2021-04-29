#include<cstdio>
#include<cmath>
using namespace std;
int totalMove=0;
void move(int from, int to, int left, int num){
	if(num==1){
		printf("%d %d\n", from+1, to+1);
		totalMove+=1;
	}else{
		move(from, left, to, num-1);
		printf("%d %d\n", from+1, to+1);
		move(left, to, from, num-1);
	}
}
int main(void){
	int n;
	scanf("%d", &n);
	printf("%d\n", int(pow(2, n)-1));
	move(0, 2, 1, n);

}
