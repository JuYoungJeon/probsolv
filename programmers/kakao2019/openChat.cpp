#include <string>
#include <vector>
#include <map>
#include<iostream>
using namespace std;

const string enter = "님이 들어왔습니다.";
const string leave = "님이 나갔습니다.";


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> uid2nick;
    vector<pair<string, string>> rs;
    for(auto& r:record){
        string action = r.substr(0, r.find(' '));
        r = r.substr(r.find(' ')+1);
        string uid = r.substr(0, r.find(' '));
        string nick = r.substr(r.find(' ')+1);
        if(action!="Leave"){
            if(uid2nick.find(uid)!=uid2nick.end())uid2nick[uid]=nick;
            else uid2nick.insert({uid, nick});
        }
        rs.push_back({uid, action});
    }
    for(auto& r: rs){
        if(r.second=="Leave")answer.push_back(uid2nick[r.first]+leave);
        if(r.second=="Enter")answer.push_back(uid2nick[r.first]+enter);
    }
    return answer;
}
