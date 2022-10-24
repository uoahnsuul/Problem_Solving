def solution(msg):
    answer = []
    dic = ['A', 'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    word = msg[0]
    i = 0
    while(i<len(msg)):
        if word in dic:
            if i != len(msg)-1:
                i += 1
            else:
                answer.append(dic.index(word)+1)
                break
            word += msg[i]
        else:
            dic.append(word)
            answer.append(dic.index(word[:-1])+1)
            word = msg[i]
        
    return answer
