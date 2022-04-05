#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> id2idx;
int rep[1000][1000];
int cnt[1000];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    for(int i=0;i<id_list.size(); i++){
        id2idx.insert({id_list[i], i});
    }
    for(int i=0;i<report.size(); i++){
        int mid = report[i].find(' ');
        int from = id2idx.find(report[i].substr(0, mid))->second;
        int to = id2idx.find(report[i].substr(mid+1, report[i].size()-mid-1))->second;
        rep[from][to]=1;
    }
    for(int i=0; i<id_list.size(); i++){
        for(int j=0;j<id_list.size(); j++){
            cnt[i]+=rep[j][i];
        }
    }
    for(int i=0;i<id_list.size(); i++){
        for(int j=0;j<id_list.size(); j++){
            if(rep[i][j]&&cnt[j]>=k) answer[i]+=1;
        }
    }
    return answer;
}
