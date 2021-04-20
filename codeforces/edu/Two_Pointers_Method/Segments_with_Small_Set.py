from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()
def read_int(): return list(map(int, read().split()))
def write(s): stdout.write(s)


n, k = read_int()
a = read_int()

i, j = 0, 0
res = 0
cur = 0
cnt = [0] * int(1 + 1e5)


def add(cur, cnt, i):
    cnt[i] += 1
    if cnt[i] == 1:
        cur += 1
    return cur


def rem(cur, cnt, i):
    cnt[i] -= 1
    if cnt[i] == 0:
        cur -= 1
    return cur


while i < n:
    while j < n:
        cur = add(cur, cnt, a[j])
        if cur > k:
            cur = rem(cur, cnt, a[j])
            break
        j += 1

    res += j - i

    cur = rem(cur, cnt, a[i])
    i += 1

print(res)
