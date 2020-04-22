# This program determines how many tasks a server can perform.

# From https://open.kattis.com/problems/server

"""
Title: Server
You are in charge of a server that needs to run some submitted tasks on a first-come, first-served basis. Each day, you can dedicate the server to run these tasks for at most 𝑇 minutes. Given the time each task takes, you want to know how many of them will be finished today.

Consider the following example. Assume 𝑇=180 and the tasks take 45,30,55,20,80, and 20 minutes (in order they are submitted). Then, only four tasks can be completed. The first four tasks can be completed because they take 150 minutes, but not the first five, because they take 230 minutes which is greater than 180. Notice that although there is enough time to perform the sixth task (which takes 20 minutes) after completing the fourth task, you cannot do that because the fifth task is not done yet.

Input
The input consists of a single test case. The first line contains two integers 𝑛 and 𝑇 where 1≤𝑛≤50 is the number of tasks and 1≤𝑇≤500. The next line contains 𝑛 positive integers no more than 100 indicating how long each task takes in order they are submitted.

Output
Display the number of tasks that can be completed in 𝑇 minutes on a first-come, first-served basis.

Sample Input 1:
6 180
45 30 55 20 80 20

Sample Output 1:
4

Sample Input 2:
10 60
20 7 10 8 10 27 2 3 10 5

Sample Output 2:
5
"""

metaData = list(map(int, input().split()))
quantityTasks = metaData[0]
T = metaData[1]

jobs = list(map(int, input().split()))

sum = 0
tasks = 0
for i in range(quantityTasks):
    sum += jobs[i]
    if sum <= T:
        tasks += 1

print(tasks)

