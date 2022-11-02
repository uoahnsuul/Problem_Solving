import math

def solution(progresses, speeds):
    answer,num = [],1
    for i in range(len(progresses)):
        progresses[i] = math.ceil((100 - progresses[i]) / speeds[i])
    maxDay = progresses[0]
    for i in range(1, len(progresses)):
        if maxDay >= progresses[i]:
            num += 1
        else:
            answer.append(num)
            num = 1
            maxDay = progresses[i]
    if num != 0:
        answer.append(num)
    return answer
