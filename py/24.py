N, K = map(lambda x: int(x), input().split(' '))

def is_palindromic(num):
    num_str = str(num)
    return num_str == num_str[::-1]

def reverse(num):
    num_str = str(num)
    return int(num_str[::-1])

step = 0
while step < K:
    if is_palindromic(N):
        break
    N += reverse(N)
    step += 1

print(N)
print(step)