#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int main(void){
	int cmd;
	scanf("%d", &cmd);
	queue<int> q;
	for(int i=0; i<cmd; i++){
		char c[10];
		scanf("%s", c);
		if(strcmp("push", c)==0){
			int val;
			scanf("%d", &val);
			q.push(val);
		}
		if(strcmp("pop",c)==0){
			if(q.empty()) printf("-1\n");
			else{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		if(strcmp("size",c)==0){
			printf("%d\n", (int)q.size());
		}
		if(strcmp("empty",c)==0){
			printf("%d\n", q.empty());
		}
		if(strcmp("front",c)==0){
			if(q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		if(strcmp("back",c)==0){
			if(q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}
	}
}
