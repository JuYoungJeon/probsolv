import sys
from collections import deque

inp = sys.stdin.readline

n = int(inp())
edges=list()
num_conn = list()
for i in range(n):
	edges.append(list())
	num_conn.append(0)
time=list()
acc_time=[0]*n

for i in range(n):
	line = inp().split()
	cost=int(line[0])
	conn=int(line[1])
	time.append(cost)
	for j in range(conn):
		v = int(line[2+j])-1
		edges[v].append(i)
		num_conn[i]+=1

q = deque(list())
for i in range(n):
	if not num_conn[i]:
		q.append(i)
		acc_time[i]=time[i]

while q:
	t = q.popleft()
	for e in edges[t]:
		if acc_time[e]<acc_time[t]+time[e]:
			acc_time[e]=acc_time[t]+time[e]
		num_conn[e]-=1
		if not num_conn[e]:
			q.append(e)
	
print(max(acc_time))
