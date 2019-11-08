# This program checks the validity of a number.

# From https://open.kattis.com/problems/fbiuniversal

"""
Title: FBI Universal Control Numbers
The FBI has recently changed its Universal Control Numbers (UCN) for identifying individuals who are in the FBI’s fingerprint database to an eight digit base 27 value with a ninth check digit. The digits used are:

0123456789ACDEFHJKLMNPRTVWX
Some letters are not used because of possible confusion with other digits:

B->8, G->C, I->1, O->0, Q->0, S->5, U->V, Y->V, Z->2
The check digit is computed as:

(2*D1 + 4*D2 + 5*D3 + 7*D4 + 8*D5 + 10*D6 + 11*D7 + 13*D8) mod 27
Where Dn is the 𝑛th digit from the left.

This choice of check digit detects any single digit error and any error transposing an adjacent pair of the original eight digits.

For this problem, you will write a program to parse a UCN input by a user. Your program should accept decimal digits and any capital letter as digits. If any of the confusing letters appear in the input, you should replace them with the corresponding valid digit as listed above. Your program should compute the correct check digit and compare it to the entered check digit. The input is rejected if they do not match otherwise the decimal (base 10) value corresponding to the first eight digits is returned.

Input
The first line of input contains a single decimal integer 𝑃, (1≤𝑃≤10000), which is the number of data sets that follow. Each data set should be processed identically and independently. Each data set consists of a single line of input. It contains the data set number, 𝐾, followed by a single space, followed by 9 decimal digits or capital (alphabetic) characters.

Output
For each data set there is one line of output. The single output line consists of the data set number, 𝐾, followed by a single space followed by the string “Invalid” (without the quotes) or the decimal value corresponding to the first eight digits.

Sample Input 1:
3
1 12345678A
2 12435678A
3 12355678A

Sample Output 1:
1 11280469652
2 Invalid
3 Invalid
"""

def convert(twentySeven, d):
    """
    This function converts a base 27 number to a base 10 number.
    """
    digits = list(str(twentySeven))

    sum = 0
    for i in range(8):
        digit = d[digits[-1 + -1 * i]]
        sum += digit * 27 ** i

    return(sum)


# d is the confusionDigitMap
d = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    'A': 10,
    'C': 11,
    'D': 12,
    'E': 13,
    'F': 14,
    'H': 15,
    'J': 16,
    'K': 17,
    'L': 18,
    'M': 19,
    'N': 20,
    'P': 21,
    'R': 22,
    'T': 23,
    'V': 24,
    'W': 25,
    'X': 26,

    # confusion digits below
    'B': 8,
    'G': 11,
    'I': 1,
    'O': 0,
    'Q': 0,
    'S': 5,
    'U': 24,
    'Y': 24,
    'Z': 2
}

def check_digit(str27, d):
    muls = [2,4,5,7,8,10,11,13]
    total = 0
    check_char = str27[-1]
    str27 = str27[:-1]
    for en, i in enumerate(str27):
        total += d[i] * muls[en]
    return total % 27 == d[check_char]

caseQuantity = int(input())

results = []

for case in range(caseQuantity):
    lineComponents = input().split()
    num = lineComponents[1]

    if not check_digit(num, d):
        results.append('Invalid')
    else:
        results.append(convert(num[:-1], d))

for i in range(caseQuantity):
    print(f"{i + 1} {results[i]}")








