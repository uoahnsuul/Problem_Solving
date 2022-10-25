def solution(n, k):
    answer, tmp = 0, ''
    flag = True
    while n:
        tmp += str(n % k)
        n = n // k
    tmp = tmp[::-1]
    num = tmp.split('0')
    for i in range(len(num)):
        flag = True
        if len(num[i]) > 0 and num[i] != '1':
            n = int(num[i])
            for j in range(2, int(n**0.5)+1):
                if n % j == 0:
                    flag = False
            if flag:
                answer += 1
    return answer
