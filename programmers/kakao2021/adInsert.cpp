#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
int t[360000];
int s2t(string s){
    int tint = stoi(s.substr(0,2))*60*60;
    tint+=stoi(s.substr(3,2))*60;
    tint+=stoi(s.substr(6, 2));
    return tint;
}
string t2s(int t){
    string s = "";
    if(to_string(t/3600).size()!=2) s+="0"+to_string(t/3600)+":";
    else s+=to_string(t/3600)+":";
    t%=3600;
    if(to_string(t/60).size()!=2) s+="0"+to_string(t/60)+":";
    else s+=to_string(t/60)+":";
    t%=60;
    if(to_string(t).size()!=2) s+="0"+to_string(t);
    else s+=to_string(t);
    return s;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(int i=0;i<logs.size(); i++){
        int beg = s2t(logs[i].substr(0,8));
        int end = s2t(logs[i].substr(9,8));
        for(int j=beg; j<end; j++) t[j]+=1;
    }
    long long added=0; int idx =0; long long maxv=0;
    for(int i=0;i<=s2t(adv_time); i++) added+=t[i];
    for(int i=s2t(adv_time); i<=s2t(play_time); i++){
        if(maxv<added){ maxv=added; answer=t2s(idx);} 
        added-=t[idx++]; added+=t[i];
    }
    return answer;
}
