def solution(s):
    answer = []
    listStr = sorted(s[2:-2].split('},{'), key=len)
    for i in listStr:
        arr = i.split(',')
        for j in range(len(arr)):
            if  arr[j] != ',' and not int(arr[j]) in answer:
                answer.append(int(arr[j]))
    return answer
