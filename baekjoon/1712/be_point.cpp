#include <iostream>

using namespace std;

int main(void){
	int a, b, c;
	cin >> a>> b>>c;
	if(c>b)
		cout <<a/(c-b)+1;
	else cout << -1;
}
