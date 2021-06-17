import sys

sys.setrecursionlimit(10**5)

ipt = sys.stdin.readline
opt = sys.stdout.write
n, m = map(int, ipt().split())
sets = list(range(n+1))

def find(a):
	pa = a
	if pa!=sets[pa]:
		sets[pa] = find(sets[pa])
	return sets[pa]

for i in range(m):
	op, a, b = map(int, ipt().split())
	if a> b:
		a, b = b, a
	if op == 0:
		pa = find(a)
		pb = find(b)
		if pa!=pb:
			sets[pb]=pa
	else:
		pa = find(a)
		pb = find(b)
		if pa==pb:
			opt("YES\n")
		else:
			opt("NO\n")

# setrecursion 10**5
# input 받을 때 sys.stdin.readline
# while로 거슬러가면 timeout..왜..????
# 거슬러올라가면서 root에 대한 cache를 해주는 것
