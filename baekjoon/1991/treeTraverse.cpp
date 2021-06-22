#include<cstdio>
using namespace std;

struct node{
	char n;
	node* l, *r;
};
node* alph[26];
void preorder(node* idx){
	printf("%c", idx->n);
	if(idx->l) preorder(idx->l);
	if(idx->r) preorder(idx->r);
}
void inorder(node* idx){
	if(idx->l) inorder(idx->l);
	printf("%c", idx->n);
	if(idx->r) inorder(idx->r);
}
void postorder(node* idx){
	if(idx->l) postorder(idx->l);
	if(idx->r) postorder(idx->r);
	printf("%c", idx->n);
}
int main(void){
	int N;
	scanf("%d", &N);
	getchar();
	for(int i=1; i<=N; i++){
		char m, l, r;
		scanf("%c %c %c", &m, &l, &r);
		getchar();
		if(!alph[m-'A']) {alph[m-'A']= new node(); alph[m-'A']->n=m;}
		if(l!='.'&&!alph[l-'A']) {alph[l-'A'] = new node(); alph[l-'A']->n=l;}
		if(r!='.'&&!alph[r-'A']) {alph[r-'A']= new node(); alph[r-'A']->n=r;}
		if(l!='.') alph[m-'A']->l=alph[l-'A'];
		if(r!='.')alph[m-'A']->r=alph[r-'A'];
	}
	preorder(alph[0]);
	printf("\n");
	inorder(alph[0]);
	printf("\n");
	postorder(alph[0]);
}
