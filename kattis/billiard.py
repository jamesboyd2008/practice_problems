# This program calculates billiards angles.

# From https://open.kattis.com/problems/billiard

"""
Title: Billiard
In a billiard table with horizontal side 𝑎 inches and vertical side 𝑏 inches, a ball is launched from the middle of the table. After 𝑠>0 seconds the ball returns to the point from which it was launched, after having made 𝑚 bounces off the vertical sides and 𝑛 bounces off the horizontal sides of the table. Find the launching angle 𝐴 (measured from the horizontal), which will be between 0 and 90 degrees inclusive, and the initial velocity of the ball.

Assume that the collisions with a side are elastic (no energy loss), and thus the velocity component of the ball parallel to each side remains unchanged. Also, assume the ball has a radius of zero. Remember that, unlike pool tables, billiard tables have no pockets.

Input
Input consists of a sequence of lines, each containing five nonnegative integers separated by whitespace. The five numbers are: 𝑎, 𝑏, 𝑠, 𝑚, and 𝑛, respectively. All numbers are positive integers not greater than 10000.

Input is terminated by a line containing five zeroes.

Output
For each input line except the last, output a line containing two real numbers (rounded to exactly two decimal places) separated by a single space. The first number is the measure of the angle 𝐴 in degrees and the second is the velocity of the ball measured in inches per second, according to the description above.

Sample Input 1:
100 100 1 1 1
200 100 5 3 4
201 132 48 1900 156
0 0 0 0 0

Sample Output 1:
45.00 141.42
33.69 144.22
3.09 7967.81
"""

import math

while True:
    # get input
    (a, b, s, m, n) = map(int, input().split())
    # handle last line
    if (a == 0) and (b == 0) and (s == 0) and (m == 0) and (n == 0):
        break
    else:
        # calculate A
        angle = math.atan( (b * n) / (a * m) ) * 180 / math.pi
        # calculate inches per second
        speed = math.sqrt( (a * m) ** 2 + (b * n) ** 2 ) / s
        # output the formatted result
        print(f"{format(angle, '.2f')} {format(speed, '.2f')}")

