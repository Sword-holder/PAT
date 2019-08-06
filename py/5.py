d = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
print(' '.join([d[int(c)] for c in str(sum(map(lambda x: int(x), input())))]))