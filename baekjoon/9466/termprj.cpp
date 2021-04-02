#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> edges;
int visited[100001]={0};
int cycle[100001]={0};
int startCycle=0;

int solution(int targetStu){
	int ans=0;
	//Cycle 을 찾은경우 cycle의 시작을 저장하고 return 0
	if(cycle[edges[targetStu]]==1) {startCycle= edges[targetStu];visited[targetStu]=1; return 0;}
	// 해당 사람을 이미 전에 visit한 경우
	if(visited[targetStu]==1) return 0;
	//함께하고 싶은 사람이 이미 visit한경우 해당 사람은 실패로 간주
	if(visited[edges[targetStu]]==1) {startCycle=targetStu;visited[targetStu]=1;return 1;}
	visited[targetStu]=1;
	cycle[targetStu]=1;
	ans+=solution(edges[targetStu]);
	cycle[targetStu]=0;
	// startCycle은 어디서부터 팀에 속하지 않은 아이인지 가리킨다
	if(startCycle==edges[targetStu]&&startCycle!=targetStu) { ans+=1; startCycle=targetStu;}
	return ans;
}

int main(void){
	int tc;
	cin >> tc;
	vector<int> ans;
	for (int i=0; i< tc; i++){
		int stuNum;
		cin >> stuNum;
		edges.clear();
		startCycle=0;
		edges.push_back(0);
		memset(visited, 0, sizeof(visited));
		memset(cycle, 0, sizeof(cycle));
		for(int j=0; j< stuNum;j++){
			int t;
			cin >> t;
			edges.push_back(t);
		}
		int res=0;
		for (int j=1; j<= stuNum;j++){
			res+=solution(j);
		}
		ans.push_back(res);
	}
	for(int i=0; i < tc; i++)
		cout << ans[i]<<'\n';
}
