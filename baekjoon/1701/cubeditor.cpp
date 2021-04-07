#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string str){
	int m = str.size();
	int j=0; 
	vector<int> substr(m);
	substr[0]=0;
	for(int i=1; i<m; i++){
		while(j>0 && str[i]!=str[j])
			j=substr[j-1];
		if(str[i]==str[j]){
			substr[i]=j+1;
			j=j+1;
		}else{
			substr[i]=0;
		}
	}
	return *max_element(substr.begin(), substr.end());
}

int main(void){
	string input; 
	getline(cin, input);
	int max_val = 0;
	for(int i=0; i<input.size(); i++)
		max_val = max(max_val, solution(input.substr(i)));
	cout << max_val;
}
