#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int d[100000][17];
int a[100000];

void preprocess(int n){
	for (int i=0; i<n ; i++)
		d[i][0] = a[i];
	for(int j=1; j< 17; j++){
		for(int i=0; i<n; i++){
			if(i+(1<<j)-1 < n){
				d[i][j] = min(d[i][j-1], d[i+(1<< (j-1))][j-1]);
			}else{
				break;
			}
		}
	}
}

int main(void){
	int n, m; 
	cin >> n >> m;

	for (int i=0; i< n; i++)
		cin >> a[i] ;

	preprocess(n);
	vector<int> ans ;
	for (int i=0; i< m; i++){
		int start, end;
		cin >> start >> end;
		start-=1;
		end-=1;
		int res =a[start];
		int k=16; 
		while(start<=end && k>=0){
			if(start + ((1<<k)-1) <=end){
				res= min(res, d[start][k]);
				start+=(1<<k);
			}
			k-=1;
		}
		ans.push_back(res);
	}
	for (int i=0; i<ans.size(); i++)
		cout << ans[i]<<'\n';
}

