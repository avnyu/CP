from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()
def read_int(): return list(map(int, read().split()))
def write(s): stdout.write(s)


n, s = read_int()
a = read_int()

i, j = 0, 0
res = 0

while i < n:
    while j < n and s - a[j] >= 0:
        s -= a[j]
        j += 1

    res = max(res, j - i)

    s += a[i]
    i += 1

print(res)
