def solution(s):
    answer = ''
    array = []
    intArr = []
    
    array = s.split(' ')
    
    for i in range(len(array)):
        intArr.append(int(array[i]))

    answer = str(min(intArr)) + " " + str(max(intArr))
    
    return answer
