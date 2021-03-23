import sys 

rotation=[(-1,0),(0,1),(1,0),(0,-1)]

def printMatrix(matrix):
	for line in matrix:
		print(" ".join(line))
	print("\n")

def solution(answer, x, y, direct, matrix,notVisited):
	global rotation
	if notVisited:
		answer+=1
		matrix[y][x]="2"
	new_direct=direct
	for i in range(len(rotation)):
		r_x, r_y=rotation[-direct+i]
		if new_direct-1<0:
			new_direct=3
		else:
			new_direct-=1
		if matrix[y+r_y][x+r_x]=="0":
			answer=solution(answer, x+r_x, y+r_y, new_direct,matrix,True)
			break
		if i== len(rotation)-1:
			back_x, back_y=rotation[-direct+1]
			if matrix[y+back_y][x+back_x]!="1":
				answer=solution(answer, x+back_x, y+back_y,direct,matrix,False)
	return answer
	

size= sys.stdin.readline()
n, m = size.strip().split(" ")
robot=sys.stdin.readline()
y,x,direction=robot.strip().split(" ")
matrix=list()
for i in range(int(n)):
	matrix.append(sys.stdin.readline().strip().split(" "))

answer=0
print(solution(answer, int(x), int(y), int(direction), matrix, True))

