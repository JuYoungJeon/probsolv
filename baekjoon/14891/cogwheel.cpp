#include<cstdio>
using namespace std;
int cogwheel[4][8];
int topPtr[4];
int main(void){
	for(int i=0; i<4; i++){
		for(int j=0; j<8; j++){
			scanf("%1d", &cogwheel[i][j]);
		}
	}
	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		int n, d;
		scanf("%d %d", &n, &d);
		n-=1;
		//left move
		int m = n;
		int l = n-1;
		int lv= topPtr[m]-2<0? topPtr[m]+8-2:topPtr[m]-2;
		bool ch= false;
		int nu=d;
		while(l>-1&&cogwheel[m][lv%8]!=cogwheel[l][(topPtr[l]+2)%8]){
			ch=true;
			l-=1;
			m-=1;
			lv=topPtr[m]-2<0? topPtr[m]+8-2: topPtr[m]-2;
			nu*=-1;
		}
		l+=1;
		nu*=-1;
		while(l<n-1){
			topPtr[l]=topPtr[l]+nu<0? topPtr[l]+nu+8: (topPtr[l]+nu)%8;
			nu*=-1;
			l+=1;
		}
		if(ch)topPtr[l]=topPtr[l]+nu<0? topPtr[l]+nu+8: (topPtr[l]+nu)%8;
		//right move
		int r = n+1;
		m=n;
		lv = topPtr[r]-2<0? topPtr[r]+8-2: topPtr[r]-2;
		ch =false;
		nu=d;
		while(r<4&&cogwheel[r][lv%8]!=cogwheel[m][(topPtr[m]+2)%8]){
			ch =true;
			r+=1;
			m+=1;
			lv=topPtr[r]-2<0? topPtr[r]+8-2: topPtr[r]-2;
			nu*=-1;
		}
		r-=1; nu*=-1;
		while(r>n+1){
			topPtr[r]=topPtr[r]+nu<0? (topPtr[r]+nu)+8: (topPtr[r]+nu)%8;
			r-=1;
			nu*=-1;
		}
		if(ch) topPtr[r]=topPtr[r]+nu<0? topPtr[r]+nu+8: (topPtr[r]+nu)%8;
		topPtr[n]=topPtr[n]+d*-1<0? topPtr[n]+d*-1+8: (topPtr[n]+d*-1)%8;
	}
	int ptr=0;
	int inc=1;
	for(int i=0; i<4; i++){
		if(cogwheel[i][topPtr[i]]==1) {
			ptr+=inc;
		}
		inc*=2;
	}
	printf("%d", ptr);
}
