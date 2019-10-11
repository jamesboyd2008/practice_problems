# This program performs Boolean operations.
# circuitmath, problem A, from icpc naq19


# From https://open.kattis.com/problems/circuitmath

"""
Title: Circuit Math
You are enrolled in the Computer Organization and Architecture course at your university. You decide to write a program to help check your work by computing the output value of a combinational digital circuit, given its inputs.

Figure 1:
https://open.kattis.com/problems/circuitmath/file/statement/en/img-0001.png

Consider the circuit shown in Figure 1, which we use for illustration. This circuit has four inputs (letters A through D on the left), each of which is either true or false. There are four ‘gates’ each of which is one of three types: AND, OR, or NOT. Each gate produces either a true or false value, depending on its inputs. The last gate (the OR on the right) produces the output of the entire circuit. We can write these three types of gates in text by their equivalent logical operators: * for AND, + for OR, and - for NOT. In what follows, we’ll use the operators rather than gates to describe circuits.


Notice that AND and OR take two inputs, whereas NOT operates on only one input. Also, we use postfix notation to write expressions involving operators (like 𝙰 𝙱 *), where the operator comes after its input(s) (just as how in Figure 1, each gate in the circuit diagram comes after its inputs).

When we describe a valid circuit in postfix notation, we use the following syntax.

An uppercase letter (A through Z) is a valid circuit. In other words, an input alone (without any gates) is a valid circuit (which produces as output its own input value).

If <C1> and <C2> are valid circuits, then ‘<C1> <C2> *’ is a valid circuit that produces the AND of the outputs of the two subcircuits.

If <C1> and <C2> are valid circuits, then ‘<C1> <C2> +’ is a valid circuit that produces the OR of the outputs of the two subcircuits.

If <C1> is a valid circuit, then ‘<C1> -’ is a valid circuit that produces the NOT of <C1>’s output.

No other description is a valid circuit.

Thus, one of the ways the circuit in Figure 1 could be described using postfix notation is as the string:

A B * C D + - +
Given a truth value (T or F) for each of the inputs (A, B, C, and D in this example), their values propagate through the gates of the circuit, and the truth value produced by the last gate is the output of the circuit. For example, when the above circuit is given inputs A=T, B=F, C=T, D=F, the output of the circuit is F.

Given an assignment to variables and a circuit description, your software should print the output of the circuit.

Input
The first line of the input consists of a single integer 𝑛, satisfying 1≤𝑛≤26, denoting the number of input variables. Then follows a line with 𝑛 space-separated characters. Each character is either 𝚃 or 𝙵, with the 𝑖th such character indicating the truth value of the input that is labeled with the 𝑖th letter of the alphabet.

The last line of input contains a circuit description, which obeys the syntax described above. Each circuit is valid, uses only the first 𝑛 letters of the alphabet as input labels, and contains at least 1 and at most 250 total non-space characters.

Note that while each variable is provided only one truth value, a variable may appear multiple times in the circuit description and serve as input to more than one gate.

Output
Print a single character, the output of the circuit (either T or F), when evaluated using the given input values.

Sample Input 1
4
T F T F
A B * C D + - +

Sample Output 1
F
"""


# get the quantity of variables, A-Z
varQuant = int(input())
# get the boolean values of those input variables
preVars = input().split(" ")
# bools
vars = []
for i in range(len(preVars)):
    if preVars[i] == 'T':
        vars.append(True)
    else:
        vars.append(False)
# vars = [True, False, True, False]

postfixy = input().split(" ") # ['A', 'B', '*', 'C', 'D', '+', '-', '+']
# create theList
theList = [] # going to be [True, False, '*', True, False, '+', '-', '+']
# ord('A') == 65      <== True
for el in postfixy:
    if el == '*' or el == '+' or el == '-':
        theList.append(el)
    else: # it's a capital letter
        # determine the capital letter's index in vars
        varIndex = ord(el) - ord('A')
        theList.append(vars[varIndex])

def apply_op(listy, n):
    if listy[n] == '*':
        new = listy[n-2] and listy[n-1]
        return listy[:n-2] + [new] + listy[n+1:]
    if listy[n] == '+':
        new = listy[n-2] or listy[n-1]
        return listy[:n-2] + [new] + listy[n+1:]
    if listy[n] == '-':
        new = not listy[n-1]
        return listy[:n-1] + [new] + listy[n+1:]


#     astrixIndex = 300
#     plusIndex = 300
#     minusIndex = 300
#     if '*' in theList:
#         astrixIndex = theList.index('*')
#     if '+' in theList:


def getIndex(listy):
    for enum, i in enumerate(listy):
        if i == '*' or i == '+' or i == '-':
            return enum

while(len(theList) > 1):
    theList = apply_op(theList, getIndex(theList))

if theList[0] == True:
    print('T')
else:
    print('F')




def andOr(a, b, operation):
    if operation == '*':
        return a and b
    return a or b

def negator(a):
    """Returns the negation of the Boolean input"""
    return(not a)
