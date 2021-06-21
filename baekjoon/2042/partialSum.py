import sys
import math

inp =sys.stdin.readline

n, m, k = map(int, inp().split())
arr=list()
for _ in range(n):
	arr.append(int(inp()))

ts = (1<<(int(math.ceil(math.log2(n)))+1))
tree=[0]*ts

def initSegTree(node, start, end):
	if start==end:
		tree[node]=arr[start]
		return tree[node]
	mid = int((start+end)/2)
	tree[node]=initSegTree(node*2, start, mid)+initSegTree(node*2+1, mid+1, end)
	return tree[node]

def modTree(node, start, end, idx, diff):
	if not (start<=idx and end>=idx): return
	tree[node]+=diff
	if start!=end:
		mid = int((start+end)/2)
		modTree(node*2, start, mid, idx, diff)
		modTree(node*2+1, mid+1, end, idx, diff)

def partSum(node, start, end, left, right):
	if right<start or left>end: return 0
	if left<=start and end <=right: return tree[node]
	mid = int((start+end)/2)
	return partSum(node*2, start, mid, left, right)+partSum(node*2+1, mid+1, end, left, right)

initSegTree(1, 0, len(arr)-1)
for _ in range(m+k):
	a, b, c = map(int, inp().split())
	if a==1:
		modTree(1, 0, len(arr)-1, b-1, c-arr[b-1])
		arr[b-1]=c
	else:
		print(partSum(1, 0, len(arr)-1, b-1, c-1))
