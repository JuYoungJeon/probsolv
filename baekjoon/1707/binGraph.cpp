#include <iostream>
#include <vector>

using namespace std;

int groupIdx[20001]={0};
int visited[20001]={0};

bool getGroupIdx(int i, vector<int> edges[20001]){
	int idx=0;
	bool res = true;
	if (visited[i]==true) return true;
	visited[i]=true;
	if(groupIdx[i]==0){
		for(int j=0; j<edges[i].size(); j++){
			if (groupIdx[edges[i][j]]==1)
				idx=2;
			if (groupIdx[edges[i][j]]==2)
				idx=1;
		}
		if (idx==0) idx=1;
		groupIdx[i]=idx;
	}else{
		idx=groupIdx[i];
	}
	int targetIdx = (idx==1)? 2: 1;
	for (int j=0;j<edges[i].size(); j++){
		if (groupIdx[edges[i][j]]==0) 
			groupIdx[edges[i][j]]=targetIdx;
		else if(groupIdx[edges[i][j]]!=targetIdx)
			return false;
		res = getGroupIdx(edges[i][j], edges);
		if (res ==false) break;
		visited[edges[i][j]]=true;
	}
	return res;
}
		

bool solution(int v, vector<int> edges[20001]){
	bool res=true;
	for(int i=1; i<=v; i++){
		if(edges[i].empty()) continue;
		res=getGroupIdx(i, edges);
		if (res ==false) break;	
	}
	return res;
}

int main(){
	int tc;
	cin >> tc;
	vector<int> ans;

	for (int i=0; i< tc; i++){
		int v, e;
		cin >> v >> e;
		for (int j=1; j<=v; j++){
			visited[j]=0;
			groupIdx[j]=0;
		}
		vector<int> edges[20001];
		for (int j=0; j<e; j++){
			int a, b;
			cin >> a>>b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		ans.push_back(solution(v, edges));
	}
	for (int i; i<tc; i++){
		if(ans[i]) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}

}
