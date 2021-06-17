import sys

inp = sys.stdin.readline

tc = int(inp())


def find(x):
	if x!=root[x]:
		root[x]=find(root[x])
	return root[x]

def union(x, y):
	px=find(x)
	py=find(y)
	if px!=py:
		root[py]=px

for t in range(tc):
	n, m = map(int, inp().split())
	ans=0
	root=[i for i in range(n+1)]
	for i in range(m):
		a, b = map(int, inp().split())
		if find(b)!=find(a):
			union(a,b)
			ans+=1
	print(ans)
## root의 parent를 바꿔줘야지 병신아:
