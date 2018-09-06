# This program finds the largest enclosed rectangle by 4 integers.
#
# from https://open.kattis.com/problems/kornislav
#
# Title: Kornislav
# Kornislav the turtle never has anything interesting to do. Since he’s going to live for three hundred years, he keeps trying to find way to kill time. This weekend he started playing "enclose the largest rectangle".
#
# To start with, Kornislav needs four positive integers. He tries to enclose a rectangle by moving in one direction, then turning 90 degrees, then walking in the new direction etc. Kornislav makes a total of three 90-degree turns and walks four segments.
#
# When walking in some direction, the number of steps he takes must be equal to one of the four chosen integers and each integer must be used exactly once. Depending on the order in which Kornislav uses the integers, his walk will make various shapes, some of which don’t contain enclosed rectangles. Write a program that calculates the largest rectangle the turtle can enclose with its walk.
#
# Input
# The first line contains four positive integers A,B,C and D (0<A,B,C,D<100), the four chosen integers.
#
# Output
# Output the largest area.
#
# Sample Input 1	        Sample Output 1
# 1 2 3 4                 3
#
# Sample Input 2         	Sample Output 2
# 4 4 3 4                 12


def strsToInts(char):
    return int(char)

line = input()
line = line.split()
line = list(map(strsToInts, line))
line.sort()
print(line[0] * line[2])
