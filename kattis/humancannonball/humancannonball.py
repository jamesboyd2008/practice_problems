# This program determines the shortest path between two points.

# From https://open.kattis.com/problems/humancannonball

"""
Human Cannonball Run
You are a world-famous circus performer, a human cannonball. This means that you climb into a big, fake cannon and launch yourself great distances to delight young and old alike. Today, you’re not alone. You are at the international human cannonball conference and exposition, where hundreds of similar circus performers have gathered together to share their experiences and practice their craft. While you normally have just one cannon to work with, at the conference there are usually lots of cannons to examine and try out.

The availability of several cannons creates some interesting opportunities for navigating the conference. If you want to travel quickly from point a to point b, you could just run straight from a to b, or, you could run to a nearby cannon and launch yourself somewhere else. From there, you can continue to run toward your destination or you can continue to use cannons in an effort to get to your destination more quickly. With cannons positioned like Figure 1, you could follow a path like the one in Figure 2 to get from a to b. The arrows show places where you launched yourself out of a cannon, and the lines show where you ran to the next cannon or to your destination.

Figure 1: Illustration of the sample input.
  
Figure 2: A suboptimal solution.
You run at a rate of 5 meters per second. All cannons launch you a distance of 50 meters, in any direction you’d like. Climbing into a cannon, launching yourself and landing takes a total of 2 seconds. Cannons are not obstacles; if a cannon is in your way, you can jump over or run around it without it slowing you down. Given your current location, a desired destination and the positions of available cannons, you want to plan how to get to the destination as quickly as possible.

Input
The input describes a single navigation problem. The first line gives a pair of real numbers, the X and Y coordinates where you’re currently located. The next line give the real-valued X and Y coordinates of the location you’d like to reach. This is followed by a line with an integer, n, the number of cannons available. The remaining n input lines each contain a pair of real values giving the X and Y coordinates for a cannon. All coordinates are measured in meters, and the value of n will be between 0 and 100, inclusive.

Output
Print a single line of output, the total number of seconds required to reach your destination as quickly as possible. Your answer must be accurate to within 0.001 seconds.

Sample Input:
25.0 100.0
190.0 57.5
4
125.0 67.5
75.0 125.0
45.0 72.5
185.0 102.5

Sample Output:
19.984901
"""

# get your initial location, (x, y)
yourCoords = tuple(map(float, input().split()))

# get destination location coordinates, (x, y)
destCoords = tuple(map(float, input().split()))

# print(yourCoords)
# print(destCoords)

# get quantity of cannons
cannonQuant = int(input())

# print(cannonQuant * 5)

# get the coords of the cannons
cannons = []
for i in range(cannonQuant):
    # get coordinates of a cannon, (x, y)
    cannonCoords = tuple(map(float, input().split()))
    cannons.append(cannonCoords)

# print(cannons)


# pickup here: use Djikstra's algo to determine the shortest path

# print the shortest path



