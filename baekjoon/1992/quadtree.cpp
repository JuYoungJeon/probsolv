#include<cstdio>
#include<string>
using namespace std;
int map[64][64];

bool checkColor(int y, int x, int m){
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			if(map[y+i][x+j]!=map[y][x]) return false;
		}
	}
	return true;
}
string divide(int y, int x, int m){
	if(checkColor(y,x,m)) return to_string(map[y][x]);
	string a="(";
	a+=divide(y, x, m/2);
	a+=divide(y, x+m/2, m/2);
	a+=divide(y+m/2, x, m/2);
	a+=divide(y+m/2, x+m/2, m/2);
	return a+")";
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	string ans = divide(0, 0, n);
	printf("%s", ans.c_str());
}
