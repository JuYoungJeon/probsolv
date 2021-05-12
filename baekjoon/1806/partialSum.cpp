#include<cstdio>
int main(void){
	int N, S;
	scanf("%d %d", &N, &S);
	int num[100000];
	for(int i=0; i<N; i++)
		scanf("%d", &num[i]);
	int minlen=N+1;
	int s=0, e=s;
	int sum=num[e];
	int curlen=1;
	while(s<N){
		if(sum>=S||e==N-1){
			if(sum>=S) minlen=minlen>curlen?curlen:minlen;
			sum-=num[s];
			s++;
			curlen--;
		}else{
			e++;
			curlen++;
			sum+=num[e];
		}
	}
	if(minlen==N+1) printf("0");
	else printf("%d", minlen);
}
