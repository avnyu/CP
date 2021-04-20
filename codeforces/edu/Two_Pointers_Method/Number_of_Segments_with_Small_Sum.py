from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()
def read_int(): return list(map(int, read().split()))
def write(s): stdout.write(s)


n, s = read_int()
a = read_int()

i, j = 0, 0
res = 0
cur = 0

while i < n:
    while j < n and cur + a[j] <= s:
        cur += a[j]
        j += 1

    res += j - i

    cur -= a[i]
    i += 1

print(res)
