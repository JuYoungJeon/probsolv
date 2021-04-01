#include <iostream>
#include <vector>

using namespace std;

int visited[1001]={0};
vector<int> perm;

int follow(int i){
	if (visited[i]) return 0;
	visited[i]=1;
	if (visited[perm[i]]==1) return 1;
	return follow(perm[i]);
}

int solution(int n){
	int numCycle=0;
	for(int i=1; i <= n; i++){
		numCycle+=follow(i);
	}
	return numCycle;
}

int main(void){
	int tc;
	cin >> tc;
	vector <int> ans;
	for (int i=0; i< tc; i++){
		int n;
		cin >> n;
		perm.clear();
		perm.push_back(0);
		for(int j=1; j<= n; j++){
			visited[j]=0;
			int tmp;
			cin >> tmp;
			perm.push_back(tmp);
		}
		ans.push_back(solution(n));
	}
	for(int i=0; i< tc; i++)
		cout << ans[i] << '\n';
}
