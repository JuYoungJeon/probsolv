

def solution(matrix):
	rightMax=list()
	leftMax=list()
	for idx in range(len(matrix)):
		if rightMax:
			if rightMax[idx-1]>matrix[idx]:
				rightMax.append(rightMax[idx-1])
			else:
				rightMax.append(matrix[idx])
		else:
			rightMax.append(matrix[idx])
		if leftMax:
			if leftMax[idx-1]>matrix[len(matrix)-1-idx]:
				leftMax.append(leftMax[idx-1])
			else:
				leftMax.append(matrix[len(matrix)-idx-1])
		else:
			leftMax.append(matrix[len(matrix)-1-idx])
	leftMax=leftMax[::-1]
	deepest = 0
	for idx in range(len(matrix)):
		if rightMax[idx] < leftMax[idx]:
			depth = rightMax[idx]-matrix[idx]
		else:
			depth = leftMax[idx]-matrix[idx]
		if depth > deepest:
			deepest=depth
	return deepest
		

print(solution([1,3,2,1,2,1,5,3,3,4,2]))
