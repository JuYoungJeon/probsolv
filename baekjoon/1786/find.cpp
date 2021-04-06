#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> subStrInfo(string substr){
	int m= substr.size();
	vector<int> str_info(m);
	int j=0;
	str_info[0]=0;
	for(int i=1; i<m; i++){
		while(j>0&& substr[i]!=substr[j]){
			j=str_info[j-1];
		}
		if(substr[i]==substr[j]){
			str_info[i]=j+1;
			j+=1;
		}else{
			str_info[i]=0;
		}
	}
	return str_info;
}

int main(){

	string t, p;
	getline(cin, t);
	getline(cin, p);

	vector <int> p_info = subStrInfo(p);

	int occ=0;
	vector<int> idxes;
	int j=0;
	int idx;
	for(int i=0; i<t.size(); i++){
		while(j>0 && t[i] != p[j]){
			j=p_info[j-1];
			idx=i-j;
		}
		if(t[i]==p[j]){
			if(j==p.size()-1) {
				occ+=1;
				idxes.push_back(idx);
			}
			if(j==0) idx=i;
			j++;
		}else{
			j=0;
		}
	}
	cout << occ <<'\n';
	for (int i=0; i< idxes.size(); i++)
		cout << idxes[i]+1 <<' ';
}
