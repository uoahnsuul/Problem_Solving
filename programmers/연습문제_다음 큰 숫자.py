def solution(n):
    answer = 0

    n_bin = bin(n)[:1:-1] + '0'
    zeros = n_bin.find('1')
    ones = n_bin[zeros:].find('0')

    return int(n_bin[:zeros+ones:-1] + '10' + '0'*zeros + '1'* (ones-1), 2)
