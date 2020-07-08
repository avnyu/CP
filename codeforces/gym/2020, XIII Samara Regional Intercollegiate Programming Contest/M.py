from sys import stdin, stdout

a = 0

for _ in range(int(stdin.readline())):
    t, l = map(int, stdin.readline().split())
    a = max(a, t) + l

print(a)