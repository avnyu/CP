import os
import random
from sys import stdin, stdout

random.seed()


def read(): return stdin.readline().strip()
def read_int(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)

N = int(1e9)
M = 1 << 30

n = 1000
a = random.randint(0, M)
v = [random.randint(0, M) for _ in range(n)]

b = 1

for i in range(n):
    b = (b | ((b << v[i]) % M))
    print('Progress: {:.1f}'.format(i * 100 / n), end='\r')

print('yes' if b & (1 << a) else 'no')
