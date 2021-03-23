#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct block{
	block * prev;
	char color;
	vector<block *> belong;
};

int readBoard(string board, block * before, block* next, int idx){
	next->color = board[idx];
	next->prev=before;
	idx+=1;
	
	if (next->color=='x'){
		for (int i=0; i<4; i++){
			block* tmp = new block();
			next->belong.push_back(tmp);
			idx = readBoard(board, next, next->belong[i], idx);
		}
	}
	return idx;
}
		

string solution(block* head){
	string reversed="";
	if (head==0) return reversed;
	if (head->color=='b' || head->color=='w') return reversed+head->color;
	reversed+=head->color;
	reversed+=solution(head->belong[2]);
	reversed+=solution(head->belong[3]);
	reversed+=solution(head->belong[0]);
	reversed+=solution(head->belong[1]);
	return reversed;
}

int main(){
	int numTc;
	cin >> numTc;
	cin.get();

	string ans[50];
	for (int i=0; i<numTc; i++){
		string board;
		getline(cin, board);

		block* head = new block();
		int len = readBoard(board, 0, head, 0);
		ans[i]=solution(head) ;
	}
	for (int i=0; i< numTc; i++){
		cout << ans[i] << '\n';
	}
}
