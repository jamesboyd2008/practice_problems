# This program translates a message.

# From https://open.kattis.com/problems/babelfish

"""
"""

line = input().split()

dictionary = {}

while (line != []):
    eng, foreign = line
    dictionary[foreign] = eng
    line = input().split()

# get the stuff to translate
while True:
    try:
        word = input()
        print(word)
    except EOFError:
        break

