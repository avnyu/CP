from functools import reduce
from sys import stdin, stdout

n = int(stdin.readline())
a = [int(i) for i in stdin.readline().split()]

s = reduce(lambda x, y: y - x, a)

for _ in range(int(stdin.readline())):
    l, r, v = map(int, stdin.readline().split())

    if l + r & 1 == 0:
        if n + l & 1: s -= v
        else: s += v
    stdout.write(str(s) + '\n')