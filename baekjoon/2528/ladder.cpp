#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct f{
	int l, r;
	int dir;
};
int main(void){
	int N, L;
	scanf("%d %d", &N, &L);
	//pair(left, right), direction
	vector<f> floor;
	for(int i=0; i<N; i++){
		int l, d;
		scanf("%d %d", &l, &d);
		if(d==0){
			f fl= {0, l, d};
			floor.push_back(fl);
		}else{
			f fl={L-l, L, d};
			floor.push_back(fl);
		}
	}
	int time=0;
	for(int i=0; i<N-1; i++){
		//fl[i+1] time만큼더하기
		if((floor[i].r<=floor[i+1].r&&floor[i].r>=floor[i+1].l)||(floor[i].l<=floor[i+1].r&&floor[i].l>=floor[i+1].l)) continue;
		if(floor[i].dir!=floor[i+1].dir){
			if(floor[i].r<floor[i+1].l){
				int a = floor[i+1].l-floor[i].r;
				if(a%2!=0) a=a/2+1;
				else a/=2;
				if(a-time<0) continue;
				else a-=time;
				time+=a;
			}else{
				int a = floor[i].l-floor[i+1].r;
				if(a%2!=0) a=a/2+1;
				else a/=2;
				if(a-time<0) continue;
				else a-=time;
				time+=a;
			}
		}
	}
	printf("%d", time);
}
//직접움직일 필요없음 
//direction이 같으면 시간걸리지않음
