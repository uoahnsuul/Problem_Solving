def solution(s):
    answer = -1
    top = -1
    stack = []
    
    for i in range(len(s)):
        if top >= 0 and stack[top] == s[i]:
                stack.pop()
                top -= 1
        else:
            top += 1
            stack.append(s[i])
    
    if top == -1 and len(s) > 1:
        answer = 1
    else:
        answer = 0
    

    return answer
