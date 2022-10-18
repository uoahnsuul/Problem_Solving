def solution(arr):
    a = arr[0]
    for j in range(len(arr)-1):
        b = arr[j+1]
        for i in range(max(a,b),(a*b)+1):
            if i%a==0 and i%b==0:
                a = i
                break
    return a
