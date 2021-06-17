import sys
from collections import deque

ipt = sys.stdin.readline
opt = sys.stdout.write

n, m = map(int, ipt().split())
dq = deque([])
top_ord = list()
edcnt = [0]*n
edges = list()
for i in range(n):
	edges.append(list())
for i in range(m):
	a, b = map(int, ipt().split())
	edges[a-1].append(b-1)
	edcnt[b-1]+=1

for i in range(n):
	if not edcnt[i]:
		dq.append(i)

while dq:
	t = dq.popleft()
	top_ord.append(t)
	for c in edges[t]:
		edcnt[c]-=1
		if edcnt[c]==0:
			dq.append(c)

for i in top_ord:
	opt(str(i+1)+"\n")
