def solution(str1, str2):
    answer = 0
    str1_m, str2_m = [], []
    inter, union = [], []
    for i in range(len(str1)-1):
        if str1[i:i+2].isalpha():
            str1_m.append(str1[i:i+2].lower())
    for i in range(len(str2)-1):
        if str2[i:i+2].isalpha():
            str2_m.append(str2[i:i+2].lower())
    str1_m.sort()
    str2_m.sort()
    i, j=0, 0
    while(i <len(str1_m) and j <len(str2_m)):
        if str1_m[i] == str2_m[j]:
            union.append(str1_m[i])
            inter.append(str1_m[i])
            i += 1
            j += 1
        elif str1_m[i] <= str2_m[j]:
            union.append(str1_m[i])
            i += 1
        else:
            union.append(str2_m[j])
            j += 1
    while(i < len(str1_m)):
        union.append(str1_m[i])
        i += 1
    while(j < len(str2_m)):
        union.append(str2_m[j])
        j += 1
    if len(union) == 0:
        return 65536
    else:
        return int(len(inter)/len(union) * 65536)
