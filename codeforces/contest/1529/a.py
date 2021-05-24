from sys import stdin, stdout


def read(): return stdin.readline().strip()
def read_int(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)


for _ in range(read_int()[0]):
    n, = read_int()
    a = read_int()
    a.sort()
    print(sum([1 if i > a[0] else 0 for i in a]))
