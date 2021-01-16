from sys import stdin, stdout
import math

def read(): return stdin.readline().strip()
def read_int(): return map(int, read().split())
def read_arr(): return [int(i) for i in read().split()]
def write(s): stdout.write(s + '\n')

n, k = read_int()
a = read_arr()

b = [0 for _ in range(n)]
for i in range(n):
    b[a[i]] += 1

res = 0
cur = min(k, b[0])
for i in range(n):
    if b[i] < cur:
        res += (cur - b[i]) * i
        cur = b[i]
res += cur * n

write(str(res))