#include<iostream>
#include<algorithm>

using namespace std;

int top[100000];
int bot[100000];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, H;
    cin >> N >> H;
    for(int i=0;i<N/2; i++){
        cin >> bot[i];
        cin >> top[i];
    }
    sort(bot, bot+N/2);
    sort(top, top+N/2);
    int ans=N;
    int ansN=0;
    for(int i=1;i<=H; i++){
        int t=N/2-(lower_bound(bot, bot+N/2, i)-bot);
        t+=N/2-(lower_bound(top, top+N/2, H-i+1)-top);
        if(t<ans){
            ans=t; ansN=1;
        }else if(t==ans){
            ansN+=1;
        }
    }
    cout << ans<< ' '<<ansN;
}
