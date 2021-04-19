#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int score[301][2];
int number[301];

int main(void){
	int n;
	cin>>n;

	for(int i=1; i<=n; i++)
		scanf("%d", &(number[i]));
	
	score[1][0]=number[1];
	score[1][1]=number[1];
	for(int i=2; i<=n; i++){
		score[i][0]=score[i-1][1]+number[i];
		score[i][1]=max(score[i-2][0], score[i-2][1])+number[i];
	}
	cout << max(score[n][0], score[n][1]);

}
