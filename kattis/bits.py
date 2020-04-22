# This program determines the quantity of ones in a binary number.

# From https://open.kattis.com/problems/bits

"""
Title: Bits
As we all know, it takes more energy to store binary numbers with lots of ones in them. Yraglac’s calculator has some batteries that are almost dead, and he’s concerned that the battery may run out as he types in a number.

The way the calculator processes numbers being entered is as follows. Initially, the calculator stores the number zero in a 32-bit internal register. As Yraglac types in each digit of his number, the register updates to store the number entered thus far. For example, when Yraglac enters the number 94, the register stores the number 9 (binary 1001) after the first key is pressed. When he presses the second key, the register clears itself and stores the number 94 (binary 1011110). What is the maximum number of one-bits in the register as Yraglac enters a number digit-by-digit?

Input
The first line contains a single integer 𝑇≤1000 giving the number of test cases. Each test case consists of a line with a single integer 𝑋 (0≤𝑋<231), the number Yraglac wants to enter.

Output
For each test case, output a single line containing the maximum number of one-bits in the storage register as the number 𝑋 is entered, digit by digit.

Sample Input 1:
6
1
2
3
4
10
94

Sample Output 1:
1
1
2
1
2
5
"""

caseQuantity = int(input())

results = []
for i in range(caseQuantity):
    onesPerDigit = []
    numChars = input()
    digitQuantity = len(numChars)

    for j in range(digitQuantity):
        num = numChars[0:j + 1]
        binStr = bin(int(num))
        result = 0

        for i in range(2, len(binStr)):
            if binStr[i] == '1':
                result += 1
        onesPerDigit.append(result)

    results.append(max(onesPerDigit))

for result in results:
    print(result)



