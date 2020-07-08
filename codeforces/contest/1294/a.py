from sys import stdin, stdout

fin = lambda: stdin.readline().split()

fout = lambda *args: stdout.write(' '.join(str(i) for i in args) + '\n')

for _ in range(int(input())):
    a, b, c, n = map(int, fin())
    fout('YES' if (a + b + c + n) %
         3 == 0 and max([a, b, c]) <= (a + b + c + n) / 3 else 'NO')
