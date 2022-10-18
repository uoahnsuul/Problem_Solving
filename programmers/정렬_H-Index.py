def solution(citations):
    answer = 0
    citations.sort(reverse=True)
    for i in range(len(citations)):
        if i >= citations[i]:
            return i
        elif i+1 < len(citations):
            if i+1 >= citations[i+1]:
                return i+1
    return len(citations)
