#include<iostream>
#include<algorithm>

using namespace std;

int cranes[50];
int boxes[10000];

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	for(int i=0;i<N; i++){
		cin >> cranes[i];
	}
	cin >> M;
	for(int i=0; i<M; i++){
		cin >> boxes[i];
	}
	sort(cranes, cranes+N, greater<int>());
	sort(boxes, boxes+M, greater<int>());
	int time=0;
	int boxidx=0;
	int craneidx=0;
	while(boxidx<M){
		if(cranes[craneidx]<boxes[boxidx]){
			if(cranes[0]<boxes[boxidx]) {
				time =-1;
				break;
			}else{
				time+=1;
				boxidx+=craneidx;
			}
		}else{
			if(craneidx==0) time+=1;
			boxidx+=time;
			craneidx+=1;
			if(boxidx>=M) break;
			if(craneidx==N){
				if((M-boxidx)%N==0)
					time+=(M-boxidx)/N;
				else
					time+=((M-boxidx)/N)+1;
				break;
			}
		}

	}
	cout << time;
}
