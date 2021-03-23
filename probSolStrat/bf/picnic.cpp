#include <iostream>

using namespace std;

int makeLine(int n, int relation[10][10],int line[10]){
	int ans=0;
	int next=-1;
	for (int i=0; i<n; i++){
		if (line[i]==0) {
			next=i;
			break;
		}
	}
	if (next==-1) return 1;
	for (int i=0; i< n; i++){
		if (relation[next][i]==1 && line[i] ==0){
			line[next]=1;
			line[i]=1;
			ans+=makeLine(n, relation, line);
			line[next]=0;
			line[i]=0;
		}
	}
	return ans;
}

int main(void){
	int numTc;
	cin >> numTc;
	int answers[numTc];
	for(int i=0; i<numTc; i++){
		int n, m;
		cin >> n >> m ;
		int relation[10][10];
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				relation[j][k]=0;
			}
		}
		// Get Relation Information 
		for (int j=0; j<m; j++){
			int a, b;
			cin >> a >> b;
			relation[a][b]=1;
			relation[b][a]=1;
		}
		int line[10]={0,0,0,0,0,0,0,0,0,0};
		answers[i]=makeLine(n, relation, line);
	}
	for (int i=0; i<numTc; i++){
		cout << answers[i]<< '\n';
	}
}
