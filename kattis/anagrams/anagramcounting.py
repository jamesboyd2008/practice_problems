# This program counts anagrams.

# From https://open.kattis.com/problems/anagramcounting

"""
Title: Anagram Counting
An anagram is a reordering of the letters in a word of phrase. For example, you can rearrange the letters of terraced to get the word retraced. Rearranging them some more will give you the word cratered. You can even make dactrere and redatrec, which are both anagrams of terraced even if they are not legitimate English words.

Input
Input contains up to 200 words, one per line. Each word consists of upper- and lower-case letters (a–z) and may have as many as 100 characters. Input ends at end of file.

Output
For every input word, output the total number of unique anagrams that can be made from it. For the purpose of this problem, upper- and lower-case letters are considered distinct.

Sample Input 1:
at
ordeals
abcdefghijklmnopqrstuvwxyz
abcdefghijklmabcdefghijklm
abcdABCDabcd

Sample Output 1:
2
5040
403291461126605635584000000
49229914688306352000000
29937600
"""
import math

lines = []

try:
    while True:
        line = input()
        lines.append(line)
except EOFError as error:
    pass

for line in lines:
    numerator = math.factorial(len(line))
    denominator = 1
    for char in set(line):
        denominator *= math.factorial(line.count(char))
    result = numerator // denominator
    print(result)









