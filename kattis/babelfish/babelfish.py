# This program translates a message.

# From https://open.kattis.com/problems/babelfish

"""
Title: Babelfish
You have just moved from Waterloo to a big city. The people here speak an incomprehensible dialect of a foreign language. Fortunately, you have a dictionary to help you understand them.

Input
Input consists of up to 100000 dictionary entries, followed by a blank line, followed by a message of up to 100000 words. Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on each line. Each word in the input is a non-empty sequence of at most 10 lowercase letters.

Output
Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated as “eh”.

Sample Input 1:	
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay

Sample Output 1:
cat
eh
loops
"""

line = input().split()

dictionary = {}

while (line != []):
    eng, foreign = line
    dictionary[foreign] = eng
    line = input().split()

while True:
    try:
        word = input()
        if word in dictionary:
            print(dictionary[word])
        else:
            print('eh')
    except EOFError:
        break

