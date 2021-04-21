#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(string name){
	int answer=0;
	int dir[2]={1,(int)name.length()-1};
	bool right=true;
	int totalChange=0;
	for(int i=0; i<name.length(); i++){
		if(name[i]!='A') totalChange+=1;
	}
	if(name[0]!='A') {
		answer+=min(name[0]-'A', 'Z'-name[dir[0]]+1);
		name[0]='A';
		totalChange-=1;
	}
	while(totalChange){
		int movement=1;
		for(int i=0; i<name.length(); i++){
			if(name[dir[0]]!='A') {
				right=true;
				break;
			}
			if(name[dir[1]]!='A'){
				right=false;
				break;
			}
			if(dir[0]==name.length()-1)
				dir[0]=0;
			else
				dir[0]+=1; 
			if(dir[1]==0)
				dir[1]=name.length()-1;
			else
				dir[1]-=1;
			movement+=1;
		}
		if(right){
			answer+=min(name[dir[0]]-'A', 'Z'-name[dir[0]]+1);
			answer+=movement;
			name[dir[0]]='A';
			if(dir[0]>0)
				dir[1]=dir[0]-1;
			else
				dir[1]=name.length()-1;
			if(dir[0]<name.length()-1)
				dir[0]=dir[0]+1;
			else
				dir[0]=0;

		}else{
			answer+=min(name[dir[1]]-'A', 'Z'-name[dir[1]]+1);
			answer+=movement;
			name[dir[1]]='A';
			if(dir[1]<name.length()-1)
				dir[0]=dir[1]+1;
			else
				dir[0]=0;
			if(dir[1]>0)
				dir[1]=dir[1]-1;
			else
				dir[1]=name.length()-1;
		}

		totalChange-=1;
	}
	return answer;
}

int main(){
	cout << solution("BBABAAAB");
}
