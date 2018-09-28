# This program determines whether a list of numbers adheres to a
# specific pattern.

# From https://open.kattis.com/problems/jollyjumpers

# Title: Jolly Jumpers
# A sequence of n>0 integers is called a jolly jumper if the absolute values of the difference between successive elements take on all the values 1 through n−1. For instance,
#
# 1 4 2 3
#
# is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether or not each of a number of sequences is a jolly jumper.
#
# Input
# Each line of input contains an integer n≤3000 followed by n integers representing the sequence. The values in the sequence are at most 300000 in absolute value. Input contains at most 10 lines.
#
# Output
# For each line of input, generate a line of output saying “Jolly” or “Not jolly”.
#
# Sample Input 1
# 4 1 4 2 3
# 5 1 4 2 -1 6
#
# Sample Output 1
# Jolly
# Not jolly

import fileinput

results = []
for line in fileinput.input():
    if line == '\n':
        break
    allNums = list(map(int, line.split()))
    n = allNums[0]
    nums = []

    for num in range(1, n + 1):
        nums.append(allNums[num])

    subs = []
    for i in range(len(nums)):
        if i != 0:
            subs.append(abs(nums[i] - nums[i - 1]))

    jollyness = True
    mustHaves = range(1, n)
    for value in mustHaves:
        if value not in subs:
            results.append('Not jolly')
            jollyness = False
            break

    if jollyness is True:
        results.append('Jolly')

print(*results, sep = '\n')








