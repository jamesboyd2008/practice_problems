# This program prints octal, decimal, and hexadecimal representations
# of integers.

# From https://open.kattis.com/problems/whichbase

"""
Which Base is it Anyway?
Programming languages such as C++ and Java can prefix characters to denote the base of constant integer values. For example, hexadecimal (base 16) constants are preceded by the string “0x”. Octal (base 8) values are preceded by the character “0” (zero). Decimal (base 10) values do not have a prefix. For example, all the following represent the same integer constant, albeit in different bases.

0x1234
011064
 4660
The prefix makes it clear to the compiler what base the value is in. Without the “0x” prefix, for example, it would be impossible for the compiler to determine if 1234 was hexadecimal. It could be octal or decimal.

For this problem, you will write a program that interprets a string of decimal digits as if it were an octal value, a decimal value or a hexadecimal value.

Input
The first line of input contains a single decimal integer P, (1≤P≤100), which is the number of data sets that follow. Each data set should be processed identically and independently.

Each data set consists of a single line of input. It contains the data set number, K, followed by a single space, followed by a string of at most 7 decimal digits.

Output
For each data set there is one line of output. The single output line consists of the data set number, K, followed by a space followed by 3 space separated decimal integers which are the value of the input as if it were interpreted to as octal, decimal and hexadecimal respectively. If the input value cannot be interpreted as an octal value, use the value 0.

Sample Input 1
4
1 1234
2 9
3 1777
4 129

Sample Output 1
1 668 1234 4660
2 0 9 9
3 1023 1777 6007
4 0 129 297
"""

numQuant = int(input())

nums = []
ks = []
for i in range(numQuant):
    line = list(map(str, input().split()))
    ks.append(line[0])
    nums.append(line[1])
lineCount = 0

for i in range(numQuant):
    numStr = nums[i]
    result = numStr

    # print iteration
    print(ks[i], end = ' ')

    # print octal
    noOct = False
    for digit in numStr:
        if int(digit) > 7:
            noOct = True
            break

    if noOct:
        print('0', end = ' ')
    else:
        sum = 0
        n = len(numStr) - 1
        for i in range(len(numStr)):
            sum += int(numStr[i]) * 8 ** n
            n -= 1

        print(sum, end = ' ')

    # print decimal
    # print(str(int(result)), end = ' ')
    print(int(result), end = ' ')

    # print hexadecimal
    sum = 0
    n = len(numStr) - 1
    for i in range(len(numStr)):
        sum += int(numStr[i]) * 16 ** n
        n -= 1

    print(sum)

