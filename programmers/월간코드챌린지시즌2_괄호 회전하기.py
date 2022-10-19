def solution(s):
    answer = 0
    ss = s+s
    for j in range(len(s)):
        stack = []
        top = -1
        for i in range(len(s)):
            if top < 0:
                stack.append(ss[i+j])
                top += 1
            elif stack[top] == '(' and ss[i+j] ==')':
                stack.pop()
                top -= 1
            elif stack[top] == '[' and ss[i+j] ==']':
                stack.pop()
                top -= 1
            elif stack[top] == '{' and ss[i+j] =='}':
                stack.pop()
                top -= 1
            else:
                stack.append(ss[i+j])
                top += 1
        if top == -1:
            answer += 1
    
    return answer
