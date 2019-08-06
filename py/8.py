a = list(map(lambda x: int(x), input().split(' ')))[1:]
floor = 0
second = 0
for i in a:
    second += (6 * (i - floor) if i > floor else 4 * (floor - i)) + 5
    floor = i
print(second)