def solution(s):
    answer = True
    top = -1
    stack = []
    for i in range(len(s)):
        if s[i] == '(':
            top += 1
            stack.append('(')
        else:
            top -= 1
        if top == -2:
            return False
    if top != -1:
        return False
    return True
