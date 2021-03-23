def solution(info, query):
    answer = []
    condition = list()
    cond_list= ["lang", "job", "exp", "food","exam"]
    queries = list()

    for i in range(len(cond_list)):
        condition.append(list())

    for person in info:
        for i, person_info in enumerate(person.strip().split()):
            condition[i].append( person_info)
    for q in query:
        candidates=range(len(info))
        cond_idx = 0
        split_q = q.split()
        for q_cond in split_q[:-1]:
            if q_cond =="-":
                cond_idx+=1
                continue
            if q_cond=="and":
                continue
            new_candidates = [i for i in candidates if condition[cond_idx][i]==q_cond]
            cond_idx+=1
            candidates=new_candidates
        q_exam = q.split()[-1]
        if not q_exam=="-":
            new_candidates=[i for i in candidates if int(condition[-1][i])>=int(q_exam)]
            candidates=new_candidates
        answer.append(len(candidates))
    return answer

print(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"], ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]))
