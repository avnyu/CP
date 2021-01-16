from sys import stdin, stdout
import math

def read(): return stdin.readline().strip()
def read_int(): return map(int, read().split())
def read_arr(): return [int(i) for i in read().split()]
def write(s): stdout.write(s + '\n')

n = int(read())
a = read_arr()
b = read_arr()

a_max = 0
cur = 0

for i in range(n):
    a_max = max(a_max, a[i])
    cur = max(cur, a_max * b[i])
    write(str(cur))