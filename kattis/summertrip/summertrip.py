# This program counts valid sequences, according to a standard of validity.

# From https://open.kattis.com/problems/summertrip

"""
Title: Summer Trip
Cartoon of items related to travel. Image from mohamed_hassan at pixabay.com
Leo has started a job in a travel agency. His first task is to organize a summer trip to an exotic overseas city. During the summer season, events of various types take place in the city: sports matches, concerts, beach parties, and many others. At any given time, there is exactly one event taking place. Events of any particular type may take place more than once during the season. The itinerary of events that Leo offers to his clients cannot be chosen arbitrarily; the company requires them to form a so-called “good itinerary.” A good itinerary is a consecutive sequence of at least two events in the summer season, where the first and last events are of different types, and they are both unique among all event types during the sequence. For example, if the first event in a good itinerary is a beach party, none of the other events during the itinerary can also be a beach party. There are no other restrictions on the event types in the sequence of a good itinerary.

Before he starts organizing the trip, Leo wants to know the total number of good itineraries that are possible given a calendar of events that will take place over the summer season.

Input
The input consists of one line with a string describing the sequence of event types in the summer season. All characters are lowercase English letters (’a’ – ’z’), with different letters represent different types of events. Character 𝑖 of the string encodes the 𝑖th event of the summer. There are no blanks or spaces in the string.

The length of the input string is at least 2 and at most 100000 characters.

Output
Print the number of good itineraries that exist for the given summer season.

Sample Input 1:
abbcccddddeeeee

Sample Output 1:
10

Sample Input 2:
thenumberofgoodstringsis

Sample Output 2:
143
"""

events = list(input())
trips = 0 # Valid summer trip quantity.
i = 0
destinationQuantity = len(events)

while ( i < destinationQuantity - 1 ):
    start = events[i]
    doubleStart = False
    j = i + 1
    while ( j < destinationQuantity ):
        end   = events[j]
        doubleEnd = False
        k = i + 1
        if j - i == 1: # i.e., only two destinations
            if start is not end:
                print("no prob 1      :", events[i:(j + 1)])
                trips += 1
        else: # three or more destinations to consider
            if start is not end:
                valid = True
                while ( k < j ):
                    if events[k] is start:
                        valid = False
                        doubleStart = True
                        break
                    if events[k] is end:
                        valid = False
                        doubleEnd = True
                        break
                    k += 1
                if valid:
                    print("no prob 2      :", events[i:(j + 1)])
                    trips += 1
        if doubleEnd:
            while (j < destinationQuantity and events[j] == end):
                print(f"double end j   : {events[i:(j + 1)]}")
                j += 1
        else:
            print('end trip j     :', events[i:(j + 1)])
            j += 1
        if doubleStart:
            while (i < destinationQuantity - 1 and events[i] == events[k]\
                and events[i + 2] is events[i]):

                print(f"double start i : {events[i:(j + 1)]}")
                i += 1
            break
    if doubleStart:
        # print("*********************************")
        i += 1
        pass
    else:
        print('end trip i     :', events[i:(j + 1)])
        i += 1
print(trips)




# pickup here: try to break it. It's timing out. You don't know why.






