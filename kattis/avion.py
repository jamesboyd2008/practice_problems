# from https://open.kattis.com/problems/avion

results = []

for line in range(5):
    words = input()
    if 'FBI' in words:
        results.append(line + 1)

if len(results) > 0:
    for result in results:
        print(str(result) + ' ', end = '')
else:
    print("HE GOT AWAY!")


