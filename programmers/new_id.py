def solution(new_id):
    answer = ''
    allowed = ['.', '-', '_']
    for i, letter in enumerate(new_id):
        if not (letter.isalpha() or (letter in allowed) or letter.isdigit()):
            continue
        if not answer and letter =='.':
                continue
        if letter.isupper():
            answer+=letter.lower()
            continue
        if len(answer) >0 and answer[-1]=='.' and letter=='.':
            continue
        answer+=letter
    if answer and answer[-1]=='.':
        answer=answer[:-1]
        
    while len(answer) <3 or len(answer) > 15:
        if len(answer)==0:
            answer+='a'
        if len(answer) < 3:
            answer+=answer[-1]
        if len(answer)>15:
            answer=answer[:15]
            if answer[-1]=='.':
                answer= answer[:-1]
            
            
    return answer

print(solution('...!@BaT#*..y.abcdefghijklm'))
print(solution(''))
print(solution('z-+.^.'))
print(solution('=.='))
print(solution('123_.def'))
print(solution('abcdefghijklmn.p'))
