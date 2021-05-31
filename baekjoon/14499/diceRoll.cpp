#include<cstdio>
#include<cstring>
int map[20][20];
int dice[5]={0,0,0,0,0};
int top=0;

//1: right, 2: left, 3: up, 4: down
int move_dir[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void printDice(){
	printf("top: %d\n", top);
	for(int i=0; i<5; i++){
		printf("dice[%d]: %d\n", i, dice[i]);
	}
}
int main(void){
	int n, m, x, y, k;
	int mm[1000];
	memset(dice, 0, sizeof(dice));
	memset(map, 0, sizeof(map));
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}
	for(int i=0; i<k; i++)
		scanf("%d", &mm[i]);

	for(int i=0; i<k; i++){
		int dx= x+move_dir[mm[i]-1][1];
		int dy= y+move_dir[mm[i]-1][0];
		if(dx<0 || dy <0 || dx>=m || dy>=n) continue;
		x=dx, y=dy;
		if(mm[i]==1) {
			int tmpV=dice[2];
			dice[2]=top;
			top=dice[1];
			dice[1]=dice[0];
			dice[0]=tmpV;
		}else if(mm[i]==2){
			int tmpV=dice[0];
			dice[0]=dice[1];
			dice[1]=top;
			top=dice[2];
			dice[2]=tmpV;
		}else if(mm[i]==3){
			int tmpV=dice[0];
			dice[0]=dice[3];
			dice[3]=top;
			top=dice[4];
			dice[4]=tmpV;
		}else {
			int tmpV = dice[4];
			dice[4]=top;
			top=dice[3];
			dice[3]=dice[0];
			dice[0]=tmpV;
		}

		if(map[dy][dx]==0) map[dy][dx]=dice[0];
		else{
			dice[0]=map[dy][dx];
			map[dy][dx]=0;
		}
		//printDice();
		printf("%d\n", top);
	}

}
