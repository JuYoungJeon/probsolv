#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> d;

int getD(int p, int n){
	int digit=1;
	int sum=0;
	while (digit<=d[n-1]){
		sum+=pow((d[n-1]/digit)%10, p);
		digit*=10;
	}
	return sum;
}
void printD(){
	for (int i=0; i<d.size(); i++)
		cout << d[i];
	cout << '\n';
}

int solution(int p){
	int i=1;
	int target = getD(p, i);
	i++;
	vector<int>::iterator idx=find(d.begin(),d.end(), target);

	while(idx==d.end()){
		d.push_back(target);
		target=getD(p, i);
		i++;
		idx=find(d.begin(), d.end(), target);
	}
	return distance(d.begin(), idx);
}

int main(){
	int a, p;
	cin >> a>> p;

	d.push_back(a);
	cout << solution(p);
}
