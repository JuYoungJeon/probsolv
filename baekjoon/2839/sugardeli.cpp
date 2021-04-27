#include <cstdio>
#include <algorithm>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	int fMax=n/5;
	int t;
	int ans=2001;
	for(int f=0; f<=fMax; f++){
		if((n-(f*5))%3==0){
			t=(n-(f*5))/3;
			ans=min(ans, t+f);
		}
	}
	if(ans==2001) printf("-1");
	else printf("%d", ans);
}
//Note: maxvalue의 initial value 를 설정할때 해당 값이 정말 max value인지 확인하기
