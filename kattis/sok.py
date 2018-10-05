# This program calculates the quantity of leftover mixers.

line1 = list(map(int, input().split()))
line2 = list(map(int, input().split()))

minDiff = None
minDiffIndex = None
for i in range(3):
    diff = line1[i] / line2[i]
    if minDiff is None or diff < minDiff:
        minDiff = diff
        minDiffIndex = i

# print(minDiffIndex)

ratio = line1[minDiffIndex] / line2[minDiffIndex]

for i in range(3):
    print(line1[i] - ratio * line2[i], end = ' ')
