#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	vector<int> a;
	vector<int> b;

	cin >> n;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		b.push_back(t);
	}

	int s=0;
	for (int i=0; i<n; i++){
		vector<int>::iterator aMin = min_element(a.begin(), a.end());
		vector<int>::iterator bMax = max_element(b.begin(), b.end());
		s+=(*aMin)*(*bMax);
		a.erase(aMin);
		b.erase(bMax);
	}
	cout << s;

}

