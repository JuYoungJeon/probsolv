#include<iostream>
#include<queue>

using namespace std;

const long long MOD = 1e9+7;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        long long ans=1;
        cin >> N;
        priority_queue<long long, vector<long long>, greater<>> pq;
        for(int i=0;i<N; i++){
            long long t;
            cin >> t;
            pq.push(t);
        }
        while(pq.size()>1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
			ans = ((a*b)%MOD*ans)%MOD;
            pq.push(a*b);
        }
        while(!pq.empty()) pq.pop();
        cout << ans <<'\n';
    }
}
