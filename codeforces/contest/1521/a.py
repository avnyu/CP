from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()
def read_int(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)


for _ in range(read_int()[0]):
    u, v = read_int()
    print('YES')
    if v + v - 1 > 1:
        print(u, u * (v + v - 1), u * v * 2)
    else:
        print(u, u * (v + v + v - 1), u * v * 3)
