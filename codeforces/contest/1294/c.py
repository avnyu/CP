from sys import stdin, stdout

fin = lambda: stdin.readline()

fout = lambda *args: stdout.write(' '.join(str(i) for i in args) + '\n')


def f(n, s=2):
    a, b = -1, -1
    for i in range(s, 22361):
        if n % i == 0:
            if a == -1:
                a = i
                n //= i
            elif i < n // i:
                return a, i, n // i
    return -1


for _ in range(int(fin())):
    n = int(fin())
    a = f(n)
    if a == -1:
        fout('NO')
    else:
        fout('YES')
        fout(a[0], a[1], a[2])
