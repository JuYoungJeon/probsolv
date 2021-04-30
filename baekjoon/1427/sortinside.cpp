#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
	string i;
	getline(cin, i);
	sort(i.begin(), i.end());
	reverse(i.begin(), i.end());
	cout << i;
}
