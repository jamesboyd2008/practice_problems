# This program solves a problem from kattis, for practice.
# https://open.kattis.com/problems/numberfun


# Title: Number Fun
# Ms. Greene is trying to design a game for her third-grade class to practice their addition, subtraction, multiplication, and division. She would like for every student in her class to be able to “think mathematically” and determine if any two given numbers can be added, subtracted, multiplied, or divided in any way to produce a third given number. However, she would like to be able to check her students’ work quickly without having to think about it herself.
#
# Help Ms. Greene by writing a program that inputs two given numbers and determines whether or not it is possible to add, subtract, multiply, or divide those two numbers in any order to produce the third number. Only one operation may be used to produce the third number.
#
# Input
# Each input file will start with a single integer N (1≤N≤10000) denoting the number of test cases. The following N lines will contain sets of 3 numbers a,b,c (1≤a,b,c≤10000).
#
# Output
# For each test case, determine whether or not it is possible to produce the third number, c, using the first two numbers, a and b, using addition, subtraction, multiplication, or division.
#
# Sample Input 1
# 6
# 1 2 3
# 2 24 12
# 5 3 1
# 9 16 7
# 7 2 14
# 12 4 2
#
# Sample Output 1
# Possible
# Possible
# Impossible
# Possible
# Possible
# Impossible

def isPossible(a, b, c):
    # what about 0?
    if (a * b == c):
        return "Possible"
    elif (a / b == c):
        return "Possible"
    elif (b / a == c):
        return "Possible"
    elif (a + b == c):
        return "Possible"
    elif (a - b == c):
        return "Possible"
    elif (b - a == c):
        return "Possible"
    else:
        return "Impossible"

def main():
    counter = 0
    results = []
    testQuantity = int(input())
    for case in range(testQuantity):
        vars = input().split()
        a = int(vars.pop(0))
        b = int(vars.pop(0))
        c = int(vars.pop(0))
        results.append(isPossible(a, b, c))
    print(*results, sep = "\n")

# if __name__ == "__main__":
main()
