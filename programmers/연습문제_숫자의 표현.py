def solution(n):
    answer = 0
    i=1
    while(i<=n):
        sum = 0
        for j in range(i, n+1):
            sum += j
            if sum == n:
                answer = answer + 1
                break
            elif sum >= n:
                break
        i = i + 1
    return answer
