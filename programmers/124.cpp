#include <string>
#include <vector>
#include <iostream>

using namespace std;

char idx[3]={'1', '2', '4'};

string solution(int n) {
    string answer = "";
    long long minN=0; 
    long long multT=1; 
    while(minN+multT<=n){
        minN+=multT;
        multT*=3;
    }
    multT/=3; 
    minN-=multT;
    int ci=-1;
    while(multT>0){
        while(minN+multT<=n&&ci<3) {minN+=multT; ci+=1;}
        if(ci==3){ ci-=1; minN-=multT;}
        answer+=idx[ci];
        multT/=3;
        ci=0;
    }
    
    return answer;
}
