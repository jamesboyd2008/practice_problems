# This program determines where a robot went whilst following a
# specific route.

# From https://open.kattis.com/problems/leftandright
#
# Title: Left and Right
# With modern technology advancement, it is now possible to deliver mail with a robot! There is a neighborhood on a long horizontal road, on which there are n houses numbered 1 to n from left to right. Every day a mail delivery robot receives a pile of letters with exactly one letter for each house. Due to mechanical restrictions, the robot cannot sort the letters. It always checks the letter on top of the pile, visits the house that should receive that letter and delivers it. The robot repeats this procedure until all the letters are delivered. As a result, each of the n houses is visited by the robot exactly once during the mail delivery of a single day.
#
# The mail delivery robot has a tracking device that records its delivery route. One day the device was broken, and the exact route was lost. However, the technical team managed to recover the moving directions of the robot from the broken device, which are represented as a string consisting of n−1 letters. The i-th letter of the string is ‘L’ (or ‘R’) if the (i+1)-th house visited by the robot is on the left (or right) of the i-th house visited. For example, if n=4 and the robot visited the houses in the order of 2,4,3,1, its moving directions would be “RLL”.
#
# With the moving directions, it may be possible to determine the order in which the robot visited the houses. The technical team has asked you to write a program to do that. There can be multiple orders producing the same moving directions, among which you should find the lexicographically earliest order.
#
# Input
# The input has a single integer n (2≤n≤2⋅105) on the first line. The second line has a string of length n−1 consisting of letters ‘L’ and ‘R’ giving the moving directions of the robot.
#
# Output
# Output the lexicographically earliest order in which the robot may have visited the houses and delivered the letters according to the moving directions.
#
# Sample Input 1
# 3
# LR
#
# Sample Output 1
# 2
# 1
# 3
#
# Sample Input 2
# 6
# RLLRL
#
# Sample Output 2
# 1
# 4
# 3
# 2
# 6
# 5
#
# Sample Input 3
# 6
# RRRLL
#
# Sample Output 3
# 1
# 2
# 3
# 6
# 5
# 4

houseCount = int(input())
dirs = input() # directions
mIndex = 1 # minimum unvisited house number
dIndex = 0 # directions index
dirLen = houseCount - 1
lGap = 0 # quantity of consecute L's previously observed
while dIndex < dirLen:
    lCount = 0
    if dirs[dIndex] == 'L':
        lCount += 1
        while dirLen - dIndex > lCount and dirs[dIndex + lCount] == 'L':
            lCount += 1
        countDown = lGap = lCount
        while countDown > 0:
            print(mIndex + countDown)
            countDown -= 1
        dIndex += lCount
    else:
        print(mIndex)
        mIndex = mIndex + 1 if lGap == 0 else mIndex + lGap + 1
        lGap = 0
        dIndex += 1

print(mIndex)
