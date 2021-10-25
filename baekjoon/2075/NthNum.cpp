#include<iostream>
#include<queue>
using namespace std;

int arr[1500][1500];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=0;i<N; i++){
        for(int j=0;j<N; j++){
            cin >> arr[i][j];
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<N; i++){
        for(int j=N-1;j>=0; j--){
            if(pq.size()<N) pq.push(arr[i][j]);
            else{
                if(pq.top()<arr[i][j]){
                    pq.pop();
                    pq.push(arr[i][j]);
                }
            }
        }
    }
    cout << pq.top() <<'\n';
}
