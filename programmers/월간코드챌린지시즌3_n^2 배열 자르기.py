def solution(n, left, right):
    answer = [0] * (right-left + 1)
    i = left // n
    j = left % n
    k=0
    while(k<len(answer)):
        while(j<=i):
            answer[k] = i+1
            j += 1
            k += 1
            if k == len(answer):
                break
            if j== n:
                i += 1
                j = 0
        while(i<j and j<n):
            answer[k] = j+1
            j += 1
            k += 1
            if k == len(answer):
                break
            if j== n:
                i += 1
                j = 0
            
    return answer
