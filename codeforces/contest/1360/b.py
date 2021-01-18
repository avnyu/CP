from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()
def read_int(): return map(int, read().split())
def read_arr(): return list(map(int, read().split()))
def write(s): stdout.write(s)

for _ in range(int(read())):
    n, = read_int()
    a = sorted(read_arr())

    print(min([a[i] - a[i - 1] for i in range(1, n)]))