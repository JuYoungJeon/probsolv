#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end()); sort(reserve.begin(), reserve.end());

    for(int i=0; i<lost.size(); ){
        auto found=find(reserve.begin(), reserve.end(), lost[i]);
        if(found!=reserve.end()){
            reserve.erase(found);
            lost.erase(lost.begin()+i);
            continue;
        }
        i++;
    }
    int answer = n-lost.size();
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j< reserve.size(); j++){
            if(reserve[j]==lost[i]+1 || reserve[j]==lost[i]-1){
                cout << reserve[j] << ' '<< lost[i] <<'\n';
                answer+=1;
                reserve.erase(reserve.begin()+j);
                break;
            }
        }
    }
    return answer;
}
