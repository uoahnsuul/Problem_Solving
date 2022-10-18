def solution(n):
    ans = 1
    while(n > 2):
        if n%2 == 0:
            n /= 2
        else:
            ans += 1
            n = (n-1) / 2
    return ans
