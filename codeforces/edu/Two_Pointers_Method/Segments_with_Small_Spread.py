from sys import stdin, stdout
import math
import heapq


def read(): return stdin.readline().strip()
def read_int(): return list(map(int, read().split()))
def write(s): stdout.write(s)


n, k = read_int()
a = read_int()

i, j = 0, 0
res = 0

cur_max = []
cur_min = []
rem_max = []
rem_min = []


def add(cur, rem, i):
    heapq.heappush(cur, i)


def rem(cur, rem, i):
    heapq.heappush(rem, i)
    while len(cur) > 0 and len(rem) > 0 and cur[0] == rem[0]:
        heapq.heappop(cur)
        heapq.heappop(rem)


while i < n:
    while j < n:
        add(cur_min, rem_min, a[j])
        add(cur_max, rem_max, -a[j])

        if -cur_min[0] - cur_max[0] > k:
            rem(cur_min, rem_min, a[j])
            rem(cur_max, rem_max, -a[j])
            break

        j += 1

    res += j - i

    rem(cur_min, rem_min, a[i])
    rem(cur_max, rem_max, -a[i])

    i += 1

print(res)
