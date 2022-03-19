#include<iostream>
#include<cstring>
#include<queue>
#include<stack>

#define ll long long
#define tp tuple<ll, int, int>
using namespace std;

struct cmp{
	bool operator()(tp a, tp b){
		if(get<0>(a)==get<0>(b)) return get<1>(a) > get <1>(b);
		return get<0>(a) > get<0>(b);
	}
};

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int arr[100000][2];
	vector<int> order;
	ll ans=0;
	priority_queue<tp, vector<tp>, cmp> pq;
	cin >> N >> K;
	for(int i=0;i<N; i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	int idx=0;
	for(int i=0;i<K; i++){
		if(i>=N) break;
		pq.push({arr[idx][1], i, arr[idx][0]});
		idx+=1;
	}

	while(!pq.empty()){
		stack<tp> tmp;
		tp c;
		do{
			c = pq.top();
			tmp.push(c);
			if(idx<N){
				pq.push({get<0>(c)+arr[idx][1], get<1>(c), arr[idx][0]});
				idx+=1;
			}
			pq.pop();
		}while(!pq.empty()&&get<0>(c)==get<0>(pq.top()));
		int tIdx=0;
		while(tIdx<tmp.size()){
			order.push_back(get<2>(tmp.top()));
			tmp.pop();
		}
	}
	for(int i=0;i<order.size(); i++){
		ans+=(ll)(i+1)*(ll)order[i];
	}
	cout << ans;
}
