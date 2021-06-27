#include<cstdio>
#include<cmath>
#include<tuple>
#include<vector>
#include<queue>
using namespace std;
pair<double, double> axis[101];
priority_queue<tuple<double, int, int>, vector<tuple<double, int, int> >, greater<tuple<double, int, int> > > dist;
int parent[101];
int find(int x){
	if (x==parent[x]) return x;
	else return parent[x]=find(parent[x]);
}
bool uni(int x, int y){
	int px=find(x);
	int py=find(y);
	if(px==py) return false;
	parent[py]=px;
	return true;
}
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		parent[i]=i;
		double x, y;
		scanf("%lf %lf", &x, &y);
		axis[i]=make_pair(y, x);
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			dist.push({sqrt(pow(axis[i].first-axis[j].first,2)+ pow(axis[i].second-axis[j].second,2)), i, j});
		}
	}
	double ans=0.0;
	while(!dist.empty()){
		auto e=dist.top();
		dist.pop();
		if(uni(get<1>(e), get<2>(e))) ans+=get<0>(e);
	}
	printf("%.2lf", ans);

}
