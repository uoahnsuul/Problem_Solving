from collections import deque

def solution(cacheSize, cities):
    answer = 0
    queue = deque([0] * cacheSize)
    cities = [i.lower() for i in cities]
    
    if cacheSize == 0:
        answer = 5 * len(cities)
        return answer

    for i in range(len(cities)):
        flag = False
        for j in range(cacheSize):
            if cities[i] == queue[j] and flag == False:
                del queue[j]
                queue.append(cities[i])
                answer += 1
                flag = True
        if flag == False:
            answer += 5
            if len(queue) == 0:
                return answer
            queue.popleft()
            queue.append(cities[i])
    return answer
