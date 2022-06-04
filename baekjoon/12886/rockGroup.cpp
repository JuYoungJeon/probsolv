#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int visited[1501][1501];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A>>B>>C;
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	int sum = A+B+C;
	q.push({A, B});
	int ans=0;
	while(!q.empty()){
		pair<int, int> t = q.front();
		int ta = t.first;
		int tb = t.second;
		int tc = sum-ta-tb;
		q.pop();
		if(visited[ta][tb]) continue;
		visited[ta][tb]=1;
		if(ta==tb&&ta==tc){
			ans=1;
			break;
		}
		if(ta<tb){
			q.push({ta+ta, tb-ta});
		}else if (ta>tb){
			q.push({ta-tb, tb+tb});
		}
		if(ta<tc){
			q.push({ta+ta, tc-ta});
		}else if(ta>tc){
			q.push({ta-tc, tc+tc});
		}
		if(tb<tc){
			q.push({tb+tb, tc-tb});
		}else if(tb>tc){
			q.push({tb-tc, tc+tc});
		}
	}
	cout << ans;
}
