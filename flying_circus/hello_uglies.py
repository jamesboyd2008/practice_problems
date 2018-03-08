x = 1
if x == 1:
    print("Hello, uglies!")
print(x)
x = 1.7
print(x)
y = 0.3
print(x + y)
x, y = 1, 2
print(x, y)
dasString = "wacky"
dasFloat = 6.6
dasInt = 66

if dasString == "wacky":
    print("String: %s" % dasString)
if isinstance(dasFloat, float) and dasFloat == 6.6:
    print("Float: %f" % dasFloat)
if isinstance(dasInt, int) and dasInt == 66:
    print("Integer: %d" % dasInt)
