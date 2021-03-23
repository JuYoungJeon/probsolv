#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;

const int connected[10][16]=
{{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0}, 
{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
{0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
{0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}};

bool checkAligned(vector<int> clocks){
	for (int i =0; i<clocks.size(); i++){
		if (clocks[i]!=12) return false;
	}
	return true;
}
int solution(vector<int> clocks, int switchId){
	int answer=9999;
	if (switchId == 10){
		if (checkAligned(clocks)){
			return 0;}
		else
			return 9999;
	}

	for (int i=0; i<4; i++){
		for (int j=0; j<16; j++) {
			if(connected[switchId][j]==1){
				if (clocks[j]+(3*i) > 12)
					clocks[j]= clocks[j]+(3*i)-12;
				else
					clocks[j]+=(3*i);
			}
		}
		answer=min(answer, solution(clocks, switchId+1)+i);
		for (int j=0; j< 16; j++){
			if(connected[switchId][j]==1){
				if (clocks[j]-(3*i)<=0)
					clocks[j]=clocks[j]-(3*i)+12;
				else
					clocks[j]-=(3*i);
			}
		}
		
	}
	return answer;
	
}
int main(){
	int numTc;
	cin >> numTc;

	int ans[30];
	for (int i=0; i< numTc;i++){
		vector<int> clocks;
		for (int j=0; j<16; j++){
			int tmp;
			cin >> tmp;
			clocks.push_back(tmp);
		}
		ans[i]=solution(clocks, 0);
		if (ans[i]==9999) ans[i]=-1;
	}
	for (int i=0; i< numTc; i++){
		cout << ans[i] <<'\n';
	}
}
