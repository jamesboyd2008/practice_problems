# This program determines the distance between buttons.

# From https://open.kattis.com/problems/unlockpattern

"""
Title: Unlock Pattern
Mobile phones may require passcodes to unlock, but people sometimes forget their passcodes. An alternative is the 9-pivot unlock pattern. Some people find such a graphical pattern easier to remember than a sequence of digits. Formally, an unlock pattern is a single stroke that visits each of the nine pivots exactly once. The pattern may start at any pivot. It may pass a pivot multiple times but only the first time counts as a visit. The phone unlocks if the pivots are visited in a predefined secret order.
A pattern is more complex if the total length of the stroke is longer. Given an unlock pattern, can you calculate its length? We assume that the pivots are aligned on a unit grid, and the stroke moves in a straight line between two consecutive pivots.

The sample input corresponds to the unlock pattern in the image.

Input
The input has three lines. Each line has three non-zero digits separated by a single space. The digits describe the order in which the pivots are visited. Every digit from 1 to 9 appears exactly once.

Output
Output the total length of the unlock pattern. Your answer is considered correct if it has an absolute or relative error of at most 10−6 from the correct answer.

Sample Input 1
6 1 9
5 2 8
4 3 7

Sample Output 1
9.8284271247
"""

import math

# for human readable mapping of dialpad numbers to coords
og_keypad = {
    1: (0, 2),
    2: (1, 2),
    3: (2, 2),
    4: (0, 1),
    5: (1, 1),
    6: (2, 1),
    7: (0, 0),
    8: (1, 0),
    9: (2, 0)
}

new_keypad = {}

# get input
digit = 1
for row in range(0, 3):
    line = input().split()
    for numStr in line:
        new_keypad[int(numStr)] = og_keypad[digit]
        digit += 1

# sum up distances
total = 0
for i in range(2, 10):
    x1, y1 = new_keypad[i - 1]
    x2, y2 = new_keypad[i]
    x = abs(x2 - x1)
    y = abs(y2 - y1)
    total += math.hypot(y, x)

print(total)



