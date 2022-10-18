def solution(brown, yellow):
    answer = []
    for i in range(1, yellow+1):
        yelLine = yellow / i
        brownSum = 2*i + 2*yelLine +4
        if brown == brownSum:
            answer.append(yelLine+2)
            answer.append(i+2)
            break
    return answer
