#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(void){
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		int h, m, s;
		scanf("%d %d %d", &h, &m, &s);
		double hd= 30*h+m/2.0+s/120.0;
		double md= 6*m + s/10.0;
		double sd= 6*s;
		double hm=min(abs(hd-md), 360-(abs(hd-md)));
		double hs=min(abs(hd-sd), 360-(abs(hd-sd)));
		double ms=min(abs(md-sd), 360-(abs(md-sd)));
		double ans = min(hm, hs);
		ans = min(ans, ms);
		printf("%lf\n", ans);
	}
}
//시간 각도 = 30*h + 30/60*m + 30/60/60*s
//한시간에 30도 (5*6)
//분 각도 = 6*m+ 6/60*s
//초 각도 = 6*s
