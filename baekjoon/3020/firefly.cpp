#include<iostream>

using namespace std;

int obs[200000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, H;
	cin >> N >> H;
	for(int i=0;i<N; i++){
		cin >> obs[i];
	}
	int minObs=N;
	int numMin=0;
	for(int i=0;i<H; i++){
		int nobs=0;
		for(int j=0;j<N; j++){
			if(j%2==0){
				if(H-obs[j]<=i) nobs+=1;
			}else{
				if(obs[j]>i) nobs+=1;
			}
		}
		if(nobs<minObs){
			numMin=1;
			minObs=nobs;
		}else if (nobs==minObs){
			numMin+=1;
		}
	}
	cout << minObs <<' '<<numMin;
}
