# This program estimates the area of a circle.

# From https://open.kattis.com/problems/estimatingtheareaofacircle

# Title: Estimating the Area of a Circle
# One way to estimate the area of a circle is to draw a square that just encompasses the circle and mark points randomly (with uniform probability) with a marker. Then, when you get tired of marking points, count up the number of points that you marked that landed in the circle and divide it by the total number of points that you marked. That gives you an idea of how large the circle is relative to the square. Your job is to judge how accurate this is for given circles and experiment outcomes.
#
# Input
# Input contains up to 1000 test cases, one test case per line. Each line has three space-separated numbers: r m c, where 0<r≤1000 is a real number with at most 5 digits past the decimal indicating the true radius of the circle, 1≤m≤100000 is an integer indicating the total number of marked points, and 0≤c≤m is an integer indicating the number of marked points that fall in the circle. Input ends with a line containing three zeros, which should not be processed.
#
# Output
# For each test case, print a line containing two numbers: the true area of the circle and the estimate according to the experiment. Both numbers may have a relative error of at most 10−5.
#
# Sample Input 1
# 1.0 100 75
# 10.0 5000 4023
# 3.0 21 17
# 0 0 0
#
# Sample Output 1
# 3.141592654 3
# 314.1592654 321.84
# 28.27433388 29.14285714

import math

exacts = []
estimates = []
while True:
    line = input()
    if line == '0 0 0':
        break
    line = line.split()
    radius = float(line[0])
    totalDots = float(line[1])
    circleDots = float(line[2])
    squareArea = (radius * 2) ** 2
    exacts.append(math.pi * radius ** 2)
    estimates.append(squareArea * circleDots / totalDots)

for (exact, estimate) in zip(exacts, estimates):
    print(exact, estimate)











