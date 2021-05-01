#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> p;
	for(int i=1; i<=n; i++)
		p.push_back(i);
	set<vector<int> > ans;
	do{
		vector<int> a;
		for(int i=0; i<m; i++){
			a.push_back(p[i]);
		}
		ans.insert(a);
	}while(next_permutation(p.begin(), p.end()));
	for(auto it=ans.begin(); it!=ans.end(); it++){
		for(int j=0; j<(*it).size(); j++)
			printf("%d ", (*it)[j]);
		printf("\n");
	}
}

