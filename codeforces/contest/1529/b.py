from sys import stdin, stdout


def read(): return stdin.readline().strip()
def read_int(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)


for _ in range(read_int()[0]):
    n, = read_int()
    a = read_int()
    a.sort()
    res = 1
    cur = int(2e9)
    for i in range(1, n):
        cur = min(cur, a[i] - a[i - 1])
        if cur < a[i]:
            break
        res = i + 1
    print(res)
