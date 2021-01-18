from sys import stdin, stdout

for _ in range(int(stdin.readline())):
    n, m = map(int, stdin.readline().split())
    print(max(2 * min(n, m), max(n, m)) ** 2)