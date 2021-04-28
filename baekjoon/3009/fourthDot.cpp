#include<cstdio>
#include<map>
using namespace std;
int main(void){
	map<int, int> x;
	map<int, int> y;
	int t_x, t_y;
	for(int i=0; i<3; i++){
		scanf("%d %d", &t_x, &t_y);
		if(x.find(t_x)==x.end()) x[t_x]=1;
		else x[t_x]+=1;
		if(y.find(t_y)==y.end()) y[t_y]=1;
		else y[t_y]+=1;
	}
	int x_a, y_a;
	for(auto it=x.begin(); it!=x.end(); it++){
		if(it->second==1) x_a=it->first;
	}
	for(auto it=y.begin(); it!=y.end(); it++){
		if(it->second==1) y_a=it->first;
	}
	printf("%d %d", x_a, y_a);
}
