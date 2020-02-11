# This program identifies data structures.

# From https://open.kattis.com/problems/guessthedatastructure

"""
Title: I Can Guess the Data Structure!
There is a bag-like data structure, supporting two operations:

1 𝑥: Throw an element 𝑥 into the bag.

2: Take out an element from the bag.

Given a sequence of operations with return values, you’re going to guess the data structure. It is a stack (Last-In, First-Out), a queue (First-In, First-Out), a priority-queue (Always take out larger elements first) or something else that you can hardly imagine!

Input
There are several test cases. Each test case begins with a line containing a single integer 𝑛 (1≤𝑛≤1000). Each of the next 𝑛 lines is either a type-1 command, or an integer 2 followed by an integer 𝑥. This means that executing the type-2 command returned the element 𝑥. The value of 𝑥 is always a positive integer not larger than 100. The input is terminated by end-of-file (EOF). The size of input file does not exceed 1MB.

Output
For each test case, output one of the following:

stack
It’s definitely a stack.

queue
It’s definitely a queue.

priority queue
It’s definitely a priority queue.

impossible
It can’t be a stack, a queue or a priority queue.

not sure
It can be more than one of the three data structures mentioned above.

Sample Input 1:
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4
1
2 1

Sample Output 1:
queue
not sure
impossible
stack
priority queue
impossible
"""

while(True):
    try:
        data = int(input())
        stackConsistent = True
        queueConsistent = True
        prioQConsistent = True
        stack = []
        queue = []
        priorityQueue = []
        for i in range(data):
            nums = list(map(int, input().split()))
            operation = nums[0]
            value = nums[1]
            if operation == 1:
                stack.append(value)
                queue.append(value)
                priorityQueue.append(value)
                priorityQueue.sort()
                priorityQueue.reverse()
            else: # it's a 2
                if len(stack) == 0 or \
                   len(queue) == 0 or \
                   len(priorityQueue) == 0:
                   stackConsistent, queueConsistent, prioQConsistent = \
                   False, False, False
                else:
                    if stack.pop() != value:
                        stackConsistent = False
                    if queue.pop(0) != value:
                        queueConsistent = False
                    if priorityQueue.pop(0) != value:
                        prioQConsistent = False

        if stackConsistent == True:
            if queueConsistent == True or prioQConsistent == True:
                print("not sure")
            else:
                print("stack")
        elif queueConsistent == True:
            if stackConsistent == True or prioQConsistent == True:
                print("not sure")
            else:
                print("queue")
        elif prioQConsistent == True:
            if stackConsistent or queueConsistent:
                print("not sure")
            else:
                print("priority queue")
        else:
            print("impossible")


    except(EOFError):
        break