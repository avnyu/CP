from sys import stdin, stdout

n = int(stdin.readline())

a = list(range(1, n + 1, 2))
if n & 1 == 0: a += [n]

stdout.write(str(len(a)) + '\n')
stdout.write(''.join([str(a[i]) + (' ' if i < len(a) - 1 else '\n') for i in range(len(a))]))