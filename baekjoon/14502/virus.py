import sys
import copy
from itertools import combinations

def spreadVirus(matrix, virusLoc):
	up = virusLoc[0]-1
	down =virusLoc[0]+1
	right = virusLoc[1]+1
	left = virusLoc[1]-1
	if up>=0 and matrix[up][virusLoc[1]]=='0':
		matrix[up][virusLoc[1]]='2'
		matrix= spreadVirus(matrix, (up, virusLoc[1]))
	if down<len(matrix) and matrix[down][virusLoc[1]]=='0':
		matrix[down][virusLoc[1]]='2'
		matrix= spreadVirus(matrix, (down, virusLoc[1]))
	if right<len(matrix[0]) and matrix[virusLoc[0]][right]=='0':
		matrix[virusLoc[0]][right]='2'
		matrix = spreadVirus(matrix, (virusLoc[0], right))
	if left>=0 and matrix[virusLoc[0]][left]=='0':
		matrix[virusLoc[0]][left]='2'
		matrix=spreadVirus(matrix, (virusLoc[0], left))
	return matrix

def checkVirus(n, m, matrix):
	count=[matrix[i].count("0") for i in range(int(n))]
	return sum(count)

def solution(n, m, matrix):
	allVirus=list()
	empty=list()
	answer=0
	for i in range(int(n)):
		for j in range(int(m)):
			if matrix[i][j]=='0':
				empty.append((i, j))
			if matrix[i][j]=='2':
				allVirus.append((i, j))
	comb = combinations(empty, 3)
	for walls in list(comb):
		new_matrix= copy.deepcopy(matrix)
		for w in walls:
			new_matrix[w[0]][w[1]]='1'
		for virusLoc in allVirus:
			new_matrix = spreadVirus(new_matrix, virusLoc)
		uninfected = checkVirus(n, m, new_matrix)
		if uninfected > answer:
			answer= uninfected

	return answer


size = sys.stdin.readline()
n, m= size.strip().split(" ")
matrix=list()
for i in range(int(n)):
	matrix.append( sys.stdin.readline().strip().split(" "))
print(solution(n, m, matrix))
	
