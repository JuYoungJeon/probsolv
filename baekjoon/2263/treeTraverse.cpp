#include<cstdio>
#include<algorithm>
using namespace std;
int inorder[100000];
int preorder[100000];
int postorder[100000];
void getPreord(int is, int ie, int ps, int pe){
	if(is>ie||ps>pe) return;
	printf("%d ", postorder[pe]);
	int il=distance(inorder, find(inorder+is, inorder+ie, postorder[pe]));
	getPreord(is, il-1, ps, ps+(il-is-1));
	getPreord(il+1, ie, ps+(il-is), pe-1);
}
int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &inorder[i]);
	}
	for(int i=0; i<n; i++) scanf("%d", &postorder[i]);
	getPreord(0, n-1, 0, n-1);
}
