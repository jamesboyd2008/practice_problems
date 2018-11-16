# This program converts decimal representations of numbers to words.

# From https://open.kattis.com/problems/wordsfornumbers
"""
Title: Words for Numbers
We have two ways of writing out numeric values; we can print them in decimal form, like 45, or we can write them out in text, like forty-five. You are a court reporter who gets paid by the character, so you would always prefer to write out numbers the long way. To that end, you are going to make sure all of your documents have decimal values written out in text rather than numbers, even if you have to get a program to help you do it.

Input
Input consists of up to 100 lines of text, ending at the end of file. All input string tokens are separated by single spaces. Each token is either a decimal number or a string of alphabet (a–z, A–Z) or simple punctuation characters. Decimal numbers in the input are integers in the range [0,99]. There are at most 100 tokens per line, and all tokens have a length of at most 15 characters.

Output
For each line of text in the input, print out a modified version of that line with all occurrences of decimal numbers replaced with words. For each decimal number you find, replace it with hyphen-separated English words representing the same value. Numbers that occur at the start of a line should start with an uppercase letter.

Sample Input 1
The speed limit is 40 mph, but you were going over 65
99 bottles of ...

Sample Output 1
The speed limit is forty mph, but you were going over sixty-five
Ninety-nine bottles of ...
"""

import copy
import fileinput

# generate list of numbers 0 - 99
ones = [
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
]
teens = [
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
]
tensFrom20 = [
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
]

nums = ["zero"]
nums += ones
nums += teens # brings us up to 19

# add 20 through 99
# iterate over tens
for ten in range(8):
    nums.append(tensFrom20[ten])
    # iterate over ones
    for one in range(9):
        nums.append(f"{tensFrom20[ten]}-{ones[one]}")

digits = ['1','2','3','4','5','6','7','8','9','0']

result = []
for line in fileinput.input():
    tokens = line.split()
    for i in range(len(tokens)):
        # is it a number?
        if tokens[i][0] in digits:
            # no more than one digit?
            if len(tokens[i]) < 2:
                numby = int(tokens[i])
                number = nums[numby]
            else:
                # it's maybe two digits
                if tokens[i][1] in digits:
                    numby = int(tokens[i][0:2])
                else: # one digit
                    numby = int(tokens[i][0])
                number = nums[numby]
            # check for beginning of line
            if i == 0:
                # capitalize it
                number = number[0].upper() + number[1:]
            # check for punctuation at end of element
            if len(str(numby)) < len(tokens[i]):
                if len(str(numby)) == 2:
                    result.append(number + tokens[i][2:])
                else: # it's one digit
                    result.append(number + tokens[i][1:])
            else: # the whole tokens[i] is a number
                result.append(number)
        else:
            result.append(tokens[i])
    result.append('\n')

for i in range(len(result)):
    # last token to avoid out of range error
    if i == len(result) - 2:
        print(result[i])
    elif i == len(result) - 1:
        continue
    else:
        # all other tokens
        if result[i] != '\n' and result[i + 1] != '\n':
            print(result[i], end = ' ')
        elif result[i] != '\n':
            print(result[i])

