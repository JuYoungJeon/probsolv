#include <iostream>
#include <algorithm>

using namespace std;

long long cache[100001][3];

int main(void){
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        int n;
        cin >> n;

        int score[100001][2];
        for(int j=0; j<2; j++){
            for(int i=1; i<=n; i++)
                cin >> score[i][j];
        }
        cache[1][0]=score[1][0];
        cache[1][1]=score[1][1];
        cache[1][2]=0;
        for (int i=2; i<=n; i++){
            cache[i][0]=max(cache[i-1][1]+score[i][0], cache[i-1][2]+score[i][0]);
            cache[i][1]=max(cache[i-1][0]+score[i][1], cache[i-1][2]+score[i][1]);
            cache[i][2]=max(cache[i-1][0], cache[i-1][1]);
        }
        long long maxVal = max(cache[n][0], cache[n][1]);
        maxVal=max(maxVal, cache[n][2]);
        cout << maxVal <<'\n';
    }
}
