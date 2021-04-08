#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
	vector<int> nums;
	vector<char> ops;
	ops.push_back('+');
	string formula;
	
	getline(cin, formula);
	string num="";
	char op;
	for(int i=0; i<formula.size(); i++){
		if(isspace(formula[i])) break;
		if(formula[i]>='0' && formula[i]<='9'){
			num+=formula[i];
			if(i==formula.size()-1){
				nums.push_back(stoi(num));
			}
		}else{
			ops.push_back(formula[i]);
			nums.push_back(stoi(num));
			num="";
		}	
	}


	int add=0;
	int sub=0;
	bool issub=false;
	for (int i=0; i<nums.size(); i++){
		if(ops[i]=='-') issub=true;
		if(issub){
			sub+=nums[i];
		}else{
			add+=nums[i];
		}
	}
	cout << add+(sub*-1);
}
