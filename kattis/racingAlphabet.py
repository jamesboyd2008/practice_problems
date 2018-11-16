# This program estimates the time it takes a runner to run a few laps.

# From https://open.kattis.com/problems/racingalphabet

"""
Title: Racing Around the Alphabet
Soccer coach Joe has invented a new fitness game that he thinks will help his players’ agility and fitness. The center circle of the soccer pitch has a diameter of 60 feet. He marks 28 evenly-spaced points on the circumference of the circle. On the first point (arbitrarily chosen) he places a pile of tokens all inscribed with the letter ’A’. On the second point he places a pile of ’B’ tokens, and so on, covering 26 of the 28 points. He places a pile of blanks (or space-characters) on the 27th point and a pile of disks imprinted with single quotation marks, on the last point.

He gives each player a slip of paper containing an aphorism, such as “WINNING ISN’T EVERYTHING IT’S THE ONLY THING” Notice that the only punctuation marks allowed are spaces and single quotation marks. Each player gets a different aphorism.

A player starts outside the circle next to the first letter of his aphorism and, on Joe’s “GO” signal, the player picks up his first disk and then takes off running around the outside of the circle, picking up the remaining disks in the order that the corresponding letters appear in the aphorism. A smart player will take the shortest route, possibly changing direction, between consecutive letters of his aphorism.

One of the assistant coaches makes a note of the player’s time. Although Joe initially envisioned all of his 20 players running around the circle simultaneously, this idea was scrapped due to contusions and fractures.

Joe wants you to write a program to estimate the expected time for one smart player to complete each of the aphorisms. Assume for simplicity that the player runs at 15 feet per second between stops for pickups and that each pickup takes 1 second.

Input
The input begins with a number N, (1≤N≤20) giving the number of aphorisms to follow. N lines follow, each one containing an aphorism made up of upper-case letters, single quotation marks, and spaces. Each aphorism will be between 8 and 120 characters inclusive.

Output
For each aphorism give the time for a smart player to complete the task. Your answer should be accurate to within 10−6 seconds.

Sample Input 1
3
WINNING ISN'T EVERYTHING IT'S THE ONLY THING
WINNERS DON'T WAIT FOR CHANCES THEY TAKE THEM
PAIN IS ONLY TEMPORARY BUT VICTORY IS FOREVER

Sample Output 1
187.6156641641
190.4108599662
193.1036536692
"""
import math # for pi

results = []
caseQuantity = int(input())

aphorisms = []
for aphorism in range(caseQuantity):
    aphorisms.append(input())

circle = []
for ascii in range(65, 91):
    circle.append(chr(ascii))
circle.append(' ')
circle.append("'")
letterLen = math.pi * 60 / 28

for aphorism in aphorisms:
    length = len(aphorism)
    totalTime = 1
    for i in range(length - 1):
        current = circle.index(aphorism[i])
        next = circle.index(aphorism[i + 1])
        normalRoute = abs(next - current)
        left = min((current, next))
        right = 28 - max((current, next))
        altRoute = left + right
        route = min((normalRoute, altRoute))
        distance = letterLen * route
        sprint = distance / 15  + 1 # seconds
        totalTime += sprint
    results.append(totalTime)

for result in results:
    print(result)

