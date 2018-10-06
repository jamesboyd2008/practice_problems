# This program calculates the quantity of leftover mixers.

# From https://open.kattis.com/problems/sok

# Title: Sok
# Mirko and Slavko bought a few liters of orange, apple and pineapple juice. They are now whipping up a non alcoholic cocktail following a recipe they found on the Internet. Sadly, they figured out too late that not only you should use recipes when making cocktails, you should also use them when planning how much juice to buy.
#
# Write a program that will determine how much of each juice they will have leftover, after they make as much cocktail as possible, respecting the recipe.
#
# Input
# The first line contains three integers, A, B, C, (1≤A,B,C≤500), the amount of orange, apple and pineapple juice they bought, in liters.
#
# The second line contains three integers, I, J, K, (1≤I,J,K≤50), the ratio of orange, apple and pineapple juice in the cocktail.
#
# Output
# The first and only line of output should contain three decimal numbers, the leftover amounts of each juice, in liters. Solutions with absolute or relative error 10−4 or smaller will be accepted.
#
# Sample Input 1
# 10 10 10
# 3 3 3
#
# Sample Output 1
# 0.000000 0.000000 0.000000
#
# Sample Input 2
# 9 9 9
# 3 2 1
#
# Sample Output 2
# 0.000000 3.000000 6.000000
#
# Sample Input 3
# 10 15 18
# 3 4 1
#
# Sample Output 3
# 0.000000 1.666667 14.666667

line1 = list(map(int, input().split()))
line2 = list(map(int, input().split()))

minDiff = None
minDiffIndex = None
for i in range(3):
    diff = line1[i] / line2[i]
    if minDiff is None or diff < minDiff:
        minDiff = diff
        minDiffIndex = i

sratio = line1[minDiffIndex] / line2[minDiffIndex]

for i in range(3):
    print(line1[i] - ratio * line2[i], end = ' ')
