#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> six;
	vector<int> one;
	for(int i=0; i<m; i++){
		int s, o;
		scanf("%d %d", &s, &o);
		six.push_back(s);
		one.push_back(o);
	}
	int min_six = *min_element(six.begin(), six.end());
	int min_one = *min_element(one.begin(), one.end());
	int ans=min_one*n;
	int ns, no;
	for(int i=1; i*6<=n; i++){
		ans=min(ans, min_six*i+min_one*(n-i*6));
	}
	ans=min(ans, min_six*(n/6+1));
	printf("%d", ans);
}
