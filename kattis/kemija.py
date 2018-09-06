# This script deletes the two characters after a vowel.

# This problem is from https://open.kattis.com/problems/kemija08

# Title: Kemija
# Luka is fooling around in chemistry class again! Instead of balancing equations he is writing coded sentences on a piece of paper. Luka modifies every word in a sentence by adding, after each vowel (letters ’a’, ’e’, ’i’, ’o’ and ’u’), the letter ’p’ and then that same vowel again. For example, the word “kemija” becomes “kepemipijapa” and the word “paprika” becomes “papapripikapa”. The teacher took Luka’s paper with the coded sentences and wants to decode them.
#
# Write a program that decodes Luka’s sentence.
#
# Input
# The coded sentence will be given on a single line. The sentence consists only of lowercase letters of the English alphabet and spaces. The words will be separated by exactly one space and there will be no leading or trailing spaces. The total number of character will be at most 100.
#
# Output
# Output the decoded sentence on a single line.
#
# Sample Input 1
# zepelepenapa papapripikapa
#
# Sample Output 1
# zelena paprika
#
# Sample Input 2
# bapas jepe doposapadnapa opovapa kepemipijapa
#
# Sample Output 2
# bas je dosadna ova kemija

vowels = ['a', 'e', 'i', 'o', 'u']
result = ''
phrase = input()

i = 0
while i < len(phrase):
    if phrase[i] in vowels:
        result += phrase[i]
        i += 2
    else:
        result += phrase[i]
    i += 1
print(result)