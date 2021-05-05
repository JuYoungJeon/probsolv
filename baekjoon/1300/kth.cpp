#include<cstdio>
#include<algorithm>
using namespace std;
int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    int l=1, h=k;
    int m, ans=k;
    while(l<=h){
        m=(l+h)/2;
		int sum=0;
        for(int i=1; i<=n; i++){
			if(m/i>n)
				sum+=n;
			else
				sum+=m/i;
        }
        if(sum>=k) ans=min(ans, m);
        if(sum>=k) h=m-1;
        else l=m+1;
    }
    printf("%d", ans);
}
//Note 오히려 볶잡하게 생각하지말자..

