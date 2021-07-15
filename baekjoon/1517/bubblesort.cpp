#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> tree;
int arr[500000];

int initTree(int node, int start, int end){
	if(start==end) tree[node]=start;
	int mid=(start+end)/2;
	int f = initTree(node*2, start, mid);
	int e = initTree(node*2+1, mid+1, end);
	return tree[node]=arr[f]>arr[e]? f: e;
}

void updateTree(int node, int start, int end, int idx, int diff){
	if(start>idx||end<idx) return;
	tree[node]+=diff;
	if(start!=end){
		int mid = (start+end)/2;
		updateTree(node*2, start, mid, idx, diff);
		updateTree(node*2+1, mide+1, end, idx, diff);
	}
}

int getIdx(int node, int start, int end, int left, int right){
	if(start<=left&&right<=end) return tree[node];
	if(left>end||right<start) return 0;
	int mid = (start+end)/2;
	return getIdx(node*2, start, mid, left, right)+getIdx(node*2+1, mid+1, end, left, right)

}

int main(void){

}
