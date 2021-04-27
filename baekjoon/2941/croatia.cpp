#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void){
	vector<string> crotia;
	crotia.push_back("c=");	crotia.push_back("c-");
	crotia.push_back("nj");	crotia.push_back("dz=");
	crotia.push_back("lj");	crotia.push_back("d-");
	crotia.push_back("s=");	crotia.push_back("z=");

	string word;
	cin >>word; 
	int ans=0;
	for(int i=0; i<word.size(); ){
		if(i+1<word.size()){
			auto it=find(crotia.begin(), crotia.end(), word.substr(i, 2));
			if(it!=crotia.end()) i+=2;
			else if(i+2<word.size()&&word.substr(i, 3)=="dz="){
				i+=3;
			}else i+=1;
			ans+=1;
		}else{
			i+=1;
			ans+=1;
		}
	}
	cout <<ans; 

}
