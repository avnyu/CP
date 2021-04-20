from sys import stdin, stdout
import math
import heapq


def read(): return stdin.readline().strip()
def read_int(): return list(map(int, read().split()))
def write(s): stdout.write(s)


n, = read_int()
a = read_int()

sparse = [[0 for _ in range(17)] for _ in range(n)]
for j in range(0, 17):
    for i in range(n):
        if j == 0:
            sparse[i][j] = a[i]
        elif i + (1 << j) <= n:
            sparse[i][j] = math.gcd(
                sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1])


def get(sparse, i: int, j: int):
    k = int(math.log2(j - i))
    return math.gcd(sparse[i][k], sparse[j - (1 << k)][k])


i, j = 0, 0
res = n + 1

while i < n:
    j = max(i + 1, j)
    cur = get(sparse, i, j)

    while j < n and cur > 1:
        cur = math.gcd(cur, a[j])
        j += 1

    if cur == 1:
        res = min(res, j - i)

    i += 1


print(res if res <= n else -1)
