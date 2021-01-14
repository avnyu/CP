from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()


def write(s): stdout.write(s)


for _ in range(int(read())):
    s = read()
    t = read()
    n, m = len(s), len(t)

    l = n * m // math.gcd(n, m)

    res = []
    ok = True
    for i in range(l):
        if s[i % n] != t[i % m]:
            write("-1\n")
            ok = False
            break
        else:
            res.append(s[i % n])

    if ok:
        write("".join(res) + "\n")
