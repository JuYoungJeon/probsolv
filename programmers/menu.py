from itertools import combinations
def solution(orders, course):
    answer = []
    candidates=dict()
    combination = list()
    for i in course:
        candidates[i]=dict()
    for o in orders:
        for c in course:
            sortedO = ''.join(sorted(o))
            combination.append(''.join(i) for i in combinations(sortedO,c))
    for comb in combination:
        for c in comb:
            if len(c) in candidates.keys():
                if c in candidates[len(c)]:
                    candidates[len(c)][c]+=1
                else:
                    candidates[len(c)][c]=1
    for c in course:
        if not candidates[c]:
            break
        maxOccur = max(candidates[c].values())
        if maxOccur < 2:
            break
        maxCand=[menu for menu, val in candidates[c].items() if val==maxOccur]
        answer+=maxCand
    answer= sorted(answer)
    return answer
print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2,3,4]))
print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],[2,3,5]))
print(solution(["XYZ", "XWY", "WXA"],[2,3,4]))
