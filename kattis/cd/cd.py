# This program determines how many CD's Jack and Jill both own.

# From https://open.kattis.com/problems/cd

nm = list(map(int, input().split()))
jackTot = nm[0]
jillTot = nm[1]

while(True):
    billion = [False] * 1000000001
    common = 0

    i = 0
    while i < jackTot:
        catalogNum = int(input())
        billion[catalogNum] = True
        i += 1

    j = 0
    while j < jillTot:
        catalogNum = int(input())
        if billion[catalogNum] == True:
            common += 1
        j += 1

    print(common)

    nm = list(map(int, input().split()))
    jackTot = nm[0]
    jillTot = nm[1]

    if jackTot == 0 and jillTot == 0:
        break

