from sys import stdin, stdout
import queue

n, m = map(int, stdin.readline().split())

g = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, c = stdin.readline().split()
    u, v = int(u), int(v)
    g[u].append((v, c))
    g[v].append((u, c))

for i in range(n + 1):
    g[i] = sorted(g[i], key=lambda x: x[1])

# print(g)

par = [-1] * (n + 1)
q = queue.Queue()

q.put(1)
par[1] = 0

while not q.empty():
    u = q.get()
    for v, c in g[u]:
        if par[v] == -1:
            par[v] = u
            q.put(v)

path = [n]
s = ''

while par[path[-1]] != 0: path.append(par[path[-1]])
path = path[::-1]

for i in range(1, len(path)):
    u = path[i - 1]
    for v, c in g[u]:
        if v == path[i]:
            s += c
            break

stdout.write(str(len(s)) + '\n')
stdout.write(' '.join([str(i) for i in path]) + '\n')
stdout.write(s + '\n')