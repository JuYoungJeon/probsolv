def solution(properties, location):
	answer = 0

	max_p = max(properties)
	max_p_idx = properties.index(max_p)
	moving_idx = max_p_idx

	target_p = properties[location]
	target_p_idx = location

	while max_p > 0:
		if max_p not in properties:
			max_p-=1
			continue
		for i in range(len(properties) - max_p_idx):
			if max_p == properties[max_p_idx+i]:
				answer+=1
				moving_idx=max_p_idx+i
				if moving_idx == location:
					return answer
		for i in range(max_p_idx):
			if max_p == properties[i]:
				answer+=1
				moving_idx =i
				if moving_idx ==location:
					return answer

		max_p_idx=moving_idx+1
		max_p=max_p-1
			
	return answer

print(solution([2, 1, 3, 2], 2))
print(solution([1, 1, 9, 1, 1, 1], 0))
print(solution([9,9,9,9,9], 0))
