import sys

def find(x):
	if x!=root[x]:
		root[x]=find(root[x])
	return root[x]

def union(x, y):
	px=find(x)
	py=find(y)
	if px!=py:
		root[py]=px

inp= sys.stdin.readline
v, e = map(int, inp().split())
edges=list()
root = [i for i in range(v+1)]
for i in range(e):
	a, b, c= map(int, inp().split())
	edges.append((a,b,c))
edges.sort(key=lambda tup: tup[2])
ans=0
for (a, b, c) in edges:
	if find(a)!=find(b):
		union(a, b)
		ans+=c
print(ans)
