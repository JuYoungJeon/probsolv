#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int cnt[20];
string cand[20];
int votes[1000][20];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();
    for(int i=0;i<N; i++){
        getline(cin, cand[i]);
    }
    int it=0;
    while(cin>>votes[it][0]){
        for(int i=1;i<N; i++){
            cin >> votes[it][i];
        }
        it++;
    }
    for(int t=0; t<N; t++){
        memset(cnt, 0, sizeof(cnt));
        for(int j=0; j<it; j++){
            for(int k=0;k<N; k++){
                if(!cand[votes[j][k]-1].empty()){
                    cnt[votes[j][k]-1]++;
                    break;
                }
            }
        }
        int minval=1001;
        int maxval=0;
        for(int i=0;i<N; i++){
            if(!cand[i].empty()&&minval>cnt[i]) minval=cnt[i];
            if(maxval<cnt[i]) maxval=cnt[i];
        }
        if(maxval>=it/2.0){
            for(int i=0;i<N; i++){
                if(cnt[i]==maxval) {
                    cout << cand[i]<<'\n';
                    return 0;
                }
            }
        }
        if(maxval==minval){
            for(int i=0;i<N; i++){
                if(!cand[i].empty()) cout << cand[i]<<'\n';
            }
            return 0;
        }
        for(int i=0; i<N; i++){
            if(cnt[i]==minval) cand[i]="";
        }
    }

}
