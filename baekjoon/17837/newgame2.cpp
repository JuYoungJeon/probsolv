#include<iostream>
using namespace std;
struct piece{
	int y, x;
	int dir;
	int idx;
	piece *next, *prev;
};
int dir[4][2] ={{0,1},{0,-1},{-1,0},{1,0}};
int map[13][13];
piece* p[10];
int n, k;

bool move(piece* cur){
	cout << "CURR:" <<cur->idx<<'\n';
	int ny = cur->y+dir[cur->dir][0];
	int nx = cur->x+dir[cur->dir][1];
	if(map[ny][nx]==2||ny<=0||ny>n||nx<=0||nx>n){ //change dir when blue or out of map
		cout <<"BLUE\n";
		if(cur->dir%2==0) cur->dir+=1;
		else cur->dir-=1;
		ny = cur->y+dir[cur->dir][0];
		nx = cur->x+dir[cur->dir][1];
		if(map[ny][nx]==2||ny<0||ny>n||nx<0||nx>n) return false;
	}else if(map[ny][nx]==1){ // change order when red
		cout<<"RED\n";
		piece * t=cur->next;
		if(cur->prev!=NULL)cur->prev->next=NULL;
		cur->prev=NULL;
		while(cur!=NULL){
			cur->next=cur->prev;
			cur->prev = t;
			if(cur->prev==NULL) break;
			cur=cur->prev;
			t = cur->next;
		}
		t=cur;
	}
	// MOVE + combine
	if(cur->prev!=NULL) cur->prev->next=NULL;
	cur->prev = NULL;
	int cnt =0;
	for(int i=0;i<n; i++){
		if(p[i]->y==ny&&p[i]->x==nx) {
			piece* t = p[i];
			while(t->next!=NULL) {t=t->next;}
			cur->prev = t;
			t->next = cur;
			break;
		}
	}
	piece*t=cur->prev;
	while(t!=NULL) {cnt+=1;t=t->prev;}
	for(int i=0;i<n; i++){
		piece*t = p[i];
		while(t!=NULL) {cout << t->idx<<' '; if(t->next==NULL) break; t=t->next;}cout<<'b' <<'\n';
		while(t!=NULL) {cout << t->idx<<' '; if(t->prev==NULL) break; t=t->prev;}cout <<'\n';
	}
	while(cur!=NULL) {cur->y = ny; cur->x = nx; cur=cur->next;cnt+=1;}
	cout << "OUT\n"<<cnt<<'\n';
	return cnt>=4;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n; i++){
		for(int j=1;j<=n; j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0; i<k; i++){
		p[i]=new piece();
		int y, x, d;
		scanf("%d %d %d", &y, &x, &d);
		p[i]->idx= i;
		p[i]->y=y; p[i]->x=x; p[i]->dir = d-1;
		p[i]->prev=NULL; p[i]->next=NULL;
	}
	bool endCond =false;
	int ans=0;
	while(ans<1001&&!endCond){
		for(int i=0;i<k; i++){
			endCond=move(p[i]);
		}
		ans+=1;
		cout <<"CNT"<< ans<<'\n';
	}
	if(ans > 1000 ) cout <<"-1\n";
	else cout << ans;
}
