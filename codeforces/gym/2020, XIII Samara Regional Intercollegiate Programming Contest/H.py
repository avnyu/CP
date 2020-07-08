from sys import stdin, stdout

n = int(stdin.readline())
deg = [0] * (n + 1)

for _ in range(1, n):
    u, v = map(int, stdin.readline().split())
    deg[u], deg[v] = deg[u] + 1, deg[v] + 1

print((sum([1 if deg[i] == 1 else 0 for i in range(n + 1)]) + 1) // 2)