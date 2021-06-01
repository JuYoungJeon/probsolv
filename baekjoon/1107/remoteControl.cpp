#include<iostream>
#include<algorithm>
using namespace std;
bool broken[10];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int target, nb;
    cin >> target>> nb;
    for(int i=0; i<nb; i++){
        int b;
        cin >> b;
        broken[b]=1;
    }
    int minporig=target>100?target-100:100-target;
    int minp=minporig;
    int startIdx= target-minp>0? target-minp:0;
    for(int i=startIdx; i<=target+minporig; i++){
        int s=i;
        int fail=false;
        if (s==0) {
            if(broken[s]) fail=true;
        }
        while(s>0){
            int but=s%10;
            s/=10;
            if(broken[but]){
                fail=true;
                break;
            }
        }
        if(!fail) {
            int res=0;
            int s=i;
            if(s==0) res=1;
            while(s>0) {s/=10; res+=1;}
            if(target>i) minp=min(minp, res+target-i);
            else minp=min(minp, res+i-target);
        }
    }
    cout << minp;
}
//NOTE: iostream에서 scanf를 왜쓰니..
