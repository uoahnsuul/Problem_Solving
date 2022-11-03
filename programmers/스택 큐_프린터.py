from collections import deque

def solution(priorities, location):
    answer = 0
    queue = deque(priorities)
    
    while queue:
        maxP = max(queue)
        cur = queue.popleft()
        
        if maxP > cur:
            queue.append(cur)
            location -= 1
            if location == -1:
                location = len(queue) - 1
        else:
            answer += 1
            location -= 1
            if location == -1:
                break
    
    return answer
