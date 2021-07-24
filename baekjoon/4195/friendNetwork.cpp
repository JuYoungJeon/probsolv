#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int par[200001];
map<string, int> m;
int numf[200001];
int getnet(int x){
	if(par[x]==x) return x;
	return par[x]=getnet(par[x]);
}
void unionf(int a, int b){
	int pa = getnet(a);
	int pb = getnet(b);
	if(pa != pb){
		par[pb]=pa;
		numf[pa]+=numf[pb];
		numf[pb]=0;
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while(tc--){
		int f;
		cin >> f;
		int friendIdx=0;
		m.clear();
		memset(par, 0, sizeof(par));
		memset(numf, 0, sizeof(numf));
		for(int i=0;i<f; i++){
			string n1, n2;
			cin >> n1 >> n2;
			if(m.find(n1)==m.end()){
				m.insert({n1, friendIdx});
				par[friendIdx]=friendIdx;
				numf[friendIdx]=1;
				friendIdx+=1;
			}
			if(m.find(n2)==m.end()){
				m.insert({n2, friendIdx});
				par[friendIdx]=friendIdx;
				numf[friendIdx]=1;
				friendIdx+=1;
			}
			if (getnet(m[n1])!=getnet(m[n2]))
				unionf(m[n1], m[n2]);
			printf("%d\n", numf[getnet(m[n1])]);
		}
	}
}
