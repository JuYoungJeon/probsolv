#include<iostream>
#include<cmath>
using namespace std;

string bin[8]={"000", "001", "010", "011", "100", "101", "110", "111"};

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string oct;
	string binary="";
	cin >> oct;
	int stlen = oct.size();
	for(int i=0;i<stlen; i++){
		binary+= bin[oct[i]-'0'];
	}
	while(binary[0]=='0') binary=binary.substr(1, binary.size());
	if(binary.empty()) binary="0";
	cout << binary;
}
