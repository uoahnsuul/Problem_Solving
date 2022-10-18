def solution(arr1, arr2):
    c1, r1 = len(arr1), len(arr1[0])
    r2 = len(arr2[0])
    answer = [[0 for j in range(r2)] for i in range(c1)]
    for i in range(c1):
        for j in range(r2):
            for k in range(r1):
                answer[i][j] += arr1[i][k] * arr2[k][j]
    return answer
