import sys
inp= sys.stdin.readline
n, m = map(int, inp().split())
arr= list(map(int, inp().split()))
tree=[0]*(n*4)

def initSegTree(node, start, end):
	if start==end :
		tree[node]=arr[start]
		return tree[node]
	mid = int((start+end)/2)
	tree[node]=initSegTree(node*2, start, mid)+initSegTree(node*2+1, mid+1, end)
	return tree[node]

def getPartSum(node, start, end, left, right):
	if start>right or end < left: return 0
	if left<=start and right>=end: return tree[node]
	mid = int((start+end)/2)
	return getPartSum(node*2, start, mid, left, right)+getPartSum(node*2+1, mid+1, end, left, right)

initSegTree(1, 0, len(arr)-1)
for _ in range(m):
	a, b = map(int, inp().split())
	print(getPartSum(1, 0, len(arr)-1, a-1, b-1))


