def solution(s):
    answer = [0,0]
    while(len(s) > 1):
        answer[0] += 1
        answer[1] += s.count('0')
        length = s.count('1')
        i=length
        s = ''
        while(i>=0):
            if 2**i <= length:
                s = s+'1'
                length = length-2**i
            else :
                if len(s) > 0:
                    s = s+'0'
            i = i-1
    return answer
