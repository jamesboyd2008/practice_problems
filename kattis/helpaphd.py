# This program finds the sums of a list of pairs of addends.
# This is from https://open.kattis.com/problems/helpaphd

"""
Jon Marius forgot how to add two numbers while doing research for his PhD. And now he has a long list of addition problems that he needs to solve, in addition to his computer science ones! Can you help him?
On his current list Jon Marius has two kinds of problems: addition problems on the form “a+b” and the ever returning problem “P=NP”. Jon Marius is a quite distracted person, so he might have so solve this last problem several times, since he keeps forgetting the solution. Also, he would like to solve these problems by himself, so you should skip these.

Input
The first line of input will be a single integer N (1≤N≤1000) denoting the number of testcases. Then follow N lines with either “P=NP” or an addition problem on the form “a+b”, where a,b∈[0,1000] are integers.

Output
Output the result of each addition. For lines containing “P=NP”, output “skipped”.

Sample Input 1
4
2+2
1+2
P=NP
0+0

Sample Output 1
4
3
skipped
0
"""

n = int(input())
results = []

for i in range(n):
    line = input()
    if line != "P=NP":
        # put something in results
        line = line.split("+")
        results.append(int(line[0]) + int(line[1]))
    else:
        results.append("skipped")

print(*results, sep = "\n")
