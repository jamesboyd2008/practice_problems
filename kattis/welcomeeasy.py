# This program counts occurences of a phrase in a string.

# From https://open.kattis.com/problems/welcomeeasy

"""
Title: Welcome to Code Jam (Easy)
Note that this is an easier version of the problem welcomehard.

So you’ve registered. We sent you a welcoming email, to welcome you to code jam. But it’s possible that you still don’t feel welcomed to code jam. That’s why we decided to name a problem “welcome to code jam.” After solving this problem, we hope that you’ll feel very welcome. Very welcome, that is, to code jam.

If you read the previous paragraph, you’re probably wondering why it’s there. But if you read it very carefully, you might notice that we have written the words “welcome to code jam” several times: 400263727 times in total. After all, it’s easy to look through the paragraph and find a ‘w’; then find an ‘e’ later in the paragraph; then find an ‘l’ after that, and so on. Your task is to write a program that can take any text and print out how many times that text contains the phrase “welcome to code jam”.

To be more precise, given a text string, you are to determine how many times the string “welcome to code jam” appears as a sub-sequence of that string. In other words, find a sequence s of increasing indices into the input string such that the concatenation of input[s[0]],input[s[1]],…,input[s[18]] is the string “welcome to code jam”.

The result of your calculation might be huge, so for convenience we would only like you to find the last 4 digits.

Input
The first line of input gives the number of test cases T,1≤T≤100. The next N lines of input contain one test case each. Each test case is a single line of text of length at most 30, containing only lower-case letters and spaces. No line will start with a space, and no line will end with a space.

Output
For each test case, “Case #x: dddd”, where x is the case number, and dddd is the last four digits of the answer. If the answer has fewer than 4 digits, please add zeroes at the front of your answer to make it exactly 4 digits long.

Sample Input 1
3
elcomew elcome to code jam
wweellccoommee to code qps jam
welcome to codejam

Sample Output 1
Case #1: 0001
Case #2: 0256
Case #3: 0000
"""

def russianNestingDoll(case):
    """This function returns the number of times a substring occurs in case."""
    occurences = 0
    letters = len(case)
    for letter in range(letters):
        if case[letter] == 'w':
            i = letter + 1
            while i < letters:
                if case[i] == 'e':
                    j = i + 1
                    while j < letters:
                        if case[j] == 'l':
                            k = j + 1
                            while k < letters:
                                if case[k] == 'c':
                                    l = k + 1
                                    while l < letters:
                                        if case[l] == 'o':
                                            m = l + 1
                                            while m < letters:
                                                if case[m] == 'm':
                                                    n = m + 1
                                                    while n < letters:
                                                        if case[n] == 'e':
                                                            o = n + 1
                                                            while o < letters:
                                                                if case[o] == ' ':
                                                                    p = o + 1
                                                                    while p < letters:
                                                                        if case[p] == 't':
                                                                            q = p + 1
                                                                            while q < letters:
                                                                                if case[q] == 'o':
                                                                                    r = q + 1
                                                                                    while r < letters:
                                                                                        if case[r] == ' ':
                                                                                            s = r + 1
                                                                                            while s < letters:
                                                                                                if case[s] == 'c':
                                                                                                    t = s + 1
                                                                                                    while t < letters:
                                                                                                        if case[t] == 'o':
                                                                                                            u = t + 1
                                                                                                            while u < letters:
                                                                                                                if case[u] == 'd':
                                                                                                                    v = u + 1
                                                                                                                    while v < letters:
                                                                                                                        if case[v] == 'e':
                                                                                                                            w = v + 1
                                                                                                                            while w < letters:
                                                                                                                                if case[w] == ' ':
                                                                                                                                    x = w + 1
                                                                                                                                    while x < letters:
                                                                                                                                        if case[x] == 'j':
                                                                                                                                            y = x + 1
                                                                                                                                            while y < letters:
                                                                                                                                                if case[y] == 'a':
                                                                                                                                                    z = y + 1
                                                                                                                                                    while z < letters:
                                                                                                                                                        if case[z] == 'm':
                                                                                                                                                            occurences += 1
                                                                                                                                                        z += 1
                                                                                                                                                y += 1
                                                                                                                                        x += 1
                                                                                                                                w += 1
                                                                                                                        v += 1
                                                                                                                u += 1
                                                                                                        t += 1
                                                                                                s += 1
                                                                                        r += 1
                                                                                q += 1
                                                                        p += 1
                                                                o += 1
                                                        n += 1
                                                m += 1
                                        l += 1
                                k += 1
                        j += 1
                i += 1

    return(occurences)


caseQuantity = int(input())
cases = []
results = []

for case in range(caseQuantity):
    cases.append(input())

for case in cases:
    result = russianNestingDoll(case)
    results.append(result)

for case in range(caseQuantity):
    num = str(results[case])
    # find last four digits
    num = num[-4:len(num)]
    print(f"Case #{case + 1}: {num.rjust(4, '0')}")












