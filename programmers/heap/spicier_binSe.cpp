#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());
    int newScoville;
    while(scoville[0]<K){
        if(scoville.size()==1) {
            answer=-1;
            break;
        }
        newScoville=scoville[0]+scoville[1]*2;
        
        scoville.erase(scoville.begin());
        scoville.erase(scoville.begin());
        if(scoville.size()==0) {
            scoville.insert(scoville.begin(), newScoville);
            answer+=1;
            continue;
        }
        int s=0, e=scoville.size()-1;
        int mid=(s+e)/2;
        while(s<=e){
            if(mid+1<scoville.size()){
                if(scoville[mid]<=newScoville&&scoville[mid+1]>=newScoville)
                    break;
            }else{
                if(scoville[mid]<=newScoville){
                    break;
                }
            }
            if(scoville[mid]<newScoville)
                s=mid+1;
            else
                e=mid-1;
            mid=(s+e)/2;
            
        }
        scoville.insert(scoville.begin()+mid+1, newScoville);
        answer+=1;
    }
    return answer;
}
int main(void){
	vector<int>a{12, 10, 9, 16, 62};
	cout << solution(a, 200) <<'\n';
}
