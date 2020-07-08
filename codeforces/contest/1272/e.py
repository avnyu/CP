n = int(input())
a = list(map(int, input().split()))

parity = lambda x: x & 1
q = []
ans = [-1] * n
graph = [[] for i in range(n)]

for i in range(n):
    if i - a[i] >= 0:
        if parity(a[i]) ^ parity(a[i - a[i]]):
            ans[i] = 1
            q.append(i)
        else:
            graph[i - a[i]].append(i)

    if i + a[i] < n:
        if parity(a[i]) ^ parity(a[i + a[i]]):
            ans[i] = 1
            q.append(i)
        else:
            graph[i + a[i]].append(i)

i = 0
while i < len(q):
    u = q[i]
    i += 1

    for v in graph[u]:
        if ans[v] == -1:
            q.append(v)
            ans[v] = ans[u] + 1

print(' '.join([str(i) for i in ans]) + '\n')