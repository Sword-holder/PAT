import time
a = [input().split(' ') for i in range(int(input()))]
a = [(x[0], time.strptime(x[1], "%H:%M:%S"), time.strptime(x[2], "%H:%M:%S")) for x in a]
print(min(a, key=lambda x: x[1])[0], max(a, key=lambda x: x[2])[0])