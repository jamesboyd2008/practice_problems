# This program finds certain substrings within a string.

# From https://open.kattis.com/problems/whatdoesthefoxsay

"""
Title: What does the fox say?
Determined to discover the ancient mystery—the sound that the fox makes—you went into the forest, armed with a very good digital audio recorder. The forest is, however, full of animals’ voices, and on your recording, many different sounds can be heard. But you are well prepared for your task: you know exactly all the sounds which other animals make. Therefore the rest of the recording—all the unidentified noises—must have been made by the fox.

Input
The first line of input contains the number of test cases T. The descriptions of the test cases follow:

The first line of each test case contains the recording—words over lower case English alphabet, separated by spaces. Each contains at most 100 letters and there are no more than 100 words. The next few lines are your pre-gathered information about other animals, in the format <animal> goes <sound>. There are no more than 100 animals, their names are not longer than 100 letters each and are actual names of animals in English. There is no fox goes ... among these lines.

The last line of the test case is exactly the question you are supposed to answer: what does the fox say?

Output
For each test case, output one line containing the sounds made by the fox, in the order from the recording. You may assume that the fox was not silent (contrary to popular belief, foxes do not communicate by Morse code).

Sample Input 1
1
toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
dog goes woof
fish goes blub
elephant goes toot
seal goes ow
what does the fox say?

Sample Output 1
wa pa pa pa pa pa pow
"""

class Case:
    """This is a test case."""
    def __init__(self, line, animals):
        self.line = line
        self.animals = animals

class Animal:
    """This is an animal."""
    def __init__(self, animal, sound):
        self.animal = animal
        self.sound = sound

# eliminate known sounds
def foxSays(case):
    """This function returns what the fox says."""
    # pickup here
    return()

# get input
caseQuantity = int(input())
cases = []

for i in range(caseQuantity):
    animals = []
    line = input()
    nextLine = input()
    while nextLine is not "what does the fox say?":
        words = nextLine.split()
        animal = words[0]
        sound = words[2:]
        newAnimal = Animal(animal, sound)
        animals.append(newAnimal)
        nextLine = input()
    case = Case(line, animals)
    cases.append(case)

results = []

# return the fox's sound
for case in cases:
    results.append(foxSays(case))

# print results
for result in results:
    print(result)















