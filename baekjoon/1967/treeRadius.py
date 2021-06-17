from collections import deque

edges=list()

def bfs(start, n):
	maxRad=0
	maxIdx=start
	visited=[False]*n
	dist=[0]*n
	d=deque([start])
	while d:
		p = d.popleft()
		visited[p]=True
		for (c, w) in edges[p]:
			if not visited[c] and dist[c]<dist[p]+w:
				dist[c]=dist[p]+w
				d.append(c)
				if maxRad<dist[c]:
					maxRad=dist[c]
					maxIdx=c
	return maxIdx, maxRad

n = int(input())
for i in range(n):
	edges.append(list())

for i in range(n-1):
	p, c, w = map(int, input().split())
	edges[p-1].append((c-1, w))
	edges[c-1].append((p-1, w))

idx, rad = bfs(0, n)
_, ans = bfs(idx, n)
print(ans)

