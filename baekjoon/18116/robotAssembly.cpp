#include<iostream>
#include<cstring>

using namespace std;

int par[1000001];
int nu[1000001];

int find(int a){
    if(par[a]==a) return par[a];
    return par[a]=find(par[a]);
}

void unionAB(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb) return;
    if(pa<=pb){
        par[pb]=pa;
        nu[pa]+=nu[pb];
    }else{
        par[pa]=pb;
        nu[pb]+=nu[pa];
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    memset(par, 0, sizeof(par));
    memset(nu, 0, sizeof(nu));
    for(int i=0;i<N; i++){
        char inst;
        cin >> inst;
        if(inst=='I'){
            int a, b;
            cin >> a >> b;
            if(!par[a]) {
                par[a]=a;
                nu[a]=1;
            }
            if(!par[b]){
                par[b]=b;
                nu[b]=1;
            }
            unionAB(a, b);
        }else if(inst=='Q'){
            int a;
            cin >> a;
            if(nu[find(a)]) cout << nu[find(a)]<<'\n';
            else cout << 1<<'\n';
        }
    }
}

