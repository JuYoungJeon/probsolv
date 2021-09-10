#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<vector<int>> reverse(vector<vector<int>> k){
    vector<vector<int>> n(k.size(), vector<int>(k.size()));
    for(int i=0;i<k.size(); i++){
        for(int j=0;j<k.size(); j++){
            n[j][k.size()-1-i]=k[i][j];
        }
    }
    return n;
}
bool checkKey(vector<vector<int>> key, vector<vector<int>> board, int y, int x){
    for(int i=0;i<key.size(); i++) {
        for(int j=0;j<key.size(); j++) {
            board[y+i][j+x]+=key[i][j];
        }
    }
    for(int i=key.size()-1; i<=board.size()-key.size(); i++){
        for(int j=key.size()-1; j<=board.size()-key.size(); j++){
            if (board[i][j]!=1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int boardsize=(key.size()-1)*2+lock.size();
    vector<vector<int>>board(boardsize, vector<int>(boardsize,0));
    for(int i=key.size()-1; i<key.size()-1+lock.size(); i++){
        for(int j=key.size()-1; j<key.size()-1+lock.size(); j++){
            board[i][j]=lock[i-key.size()+1][j-key.size()+1];
        }
    }
    for(int i=0;i<4; i++){
        for(int j=0;j<=boardsize-key.size(); j++){
            for(int k=0;k<=boardsize-key.size();k++){
                answer=checkKey(key, board, j, k);
                if(answer) return true;
            }
        }
        key = reverse(key);
    }
    return answer;
}
