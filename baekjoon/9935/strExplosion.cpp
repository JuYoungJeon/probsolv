#include<iostream>
#include<string>
using namespace std;

char ans[1000000];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str, exp;
    cin >> str >> exp;
    int idx=0;
    for(int i=0;i<str.size(); i++){
        ans[idx++]=str[i];
        bool found=true;
        for(int j=0; j<exp.size(); j++){
            if(ans[idx-1-j]!=exp[exp.size()-1-j]){
                found=false;
                break;
            }   
        }
        if(found){
            idx=idx-exp.size();
        }   
    }
    if(idx==0) cout << "FRULA";
    else{
        for(int i=0;i<idx; i++){
            cout << ans[i];
        }   
    }   
}

