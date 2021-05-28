#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct block{
	int y, x;
	block*next;
	block*prev;
};
int map[101][101];
queue<pair<int, char> > mov;
block* snake_s, *snake_e;

int move(int n){
	int sec=0;
	int dy=0, dx=1; 
	pair <int, char> next_mov = mov.front();
	mov.pop();
	bool eatApple=false;
	bool prevEatApple=false;
	while(1){
		//move head
		sec+=1;
		block* t = new block();
		t->y=snake_s->y+dy; t->x= snake_s->x+dx;
		t->next=snake_s; t->prev=NULL;
		if(map[t->y][t->x]==1) { prevEatApple=eatApple; eatApple=true;}
		else {prevEatApple=eatApple; eatApple=false;}
		if(t->y==0|| t->x==0||t->y==n+1||t->x==n+1) break;
		if(map[t->y][t->x]==2) break;
		map[t->y][t->x]=2;
		snake_s->prev = t;
		snake_s= t;
		//remove tail
		if(!prevEatApple){
			map[snake_e->y][snake_e->x]=0;
			block* t = snake_e;
			snake_e = snake_e->prev;
			snake_e->next = NULL;
			delete t;
		}

		if(sec==next_mov.first){
			 if(dy==0){
				if(next_mov.second=='D') dy=dx;
				else dy=dx*-1;
				dx=0;
			 }else{
				if(next_mov.second=='D') dx=dy*-1;
				else dx= dy;
				dy=0;
			 }
			 if (!mov.empty()){
			 	next_mov= mov.front();
			 	mov.pop();
			}
		}
	}
	while(snake_s!=NULL){
		block* s = snake_s;
		snake_s=snake_s->next;
		delete s;
	}
	return sec;
}
int main(void){
	int n, k, l;
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++){
		int x, y;
		scanf("%d %d", &y, &x);
		map[y][x]=1;
	}
	scanf("%d", &l);
	for(int i=0; i<l; i++){
		int s;
		char d;
		scanf("%d %c", &s, &d);
		mov.push(make_pair(s, d));
	}


	snake_s=new block();
	snake_s->y=1; snake_s->x= 1;  
	snake_s->next=NULL, snake_s->prev=NULL;
	snake_e= snake_s;
	map[snake_s->y][snake_s->x]=2;

	printf("%d", move(n));
	return 0;
}
