#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N, int number){
    vector< vector<int> > pool(9, vector<int>());
    pool[1].push_back(N);
    if(number==N) return 1;
    for(int i=2; i<9; i++){
        string N_str=to_string(N);
        string value="";
        for(int k=0; k<i; k++) value+=N_str;
        pool[i].push_back(stoi(value));
        if(stoi(value)==number) return i;
        for(int j=1; j<i; j++){
            for(int k=0; k<pool[j].size(); k++){
                for(int l=0; l<pool[i-j].size(); l++){
                    pool[i].push_back(pool[j][k]+pool[i-j][l]);
                    if(pool[j][k]+pool[i-j][l]==number) return i;
                    pool[i].push_back(pool[j][k]-pool[i-j][l]);
                    if(pool[j][k]-pool[i-j][l]==number) return i;
                    pool[i].push_back(pool[j][k]*pool[i-j][l]);
                    if(pool[j][k]*pool[i-j][l]==number) return i;
                    if(pool[i-j][l]!=0){
                        pool[i].push_back(pool[j][k]/pool[i-j][l]);
                        if(pool[j][k]/pool[i-j][l]==number) return i;
                    }
                }
            }
        }
    }
    return -1;
}
