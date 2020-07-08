from math import gcd

n = int(input())
a = [int(i) for i in input().split()]

lcm = lambda x, y: x * y // gcd(x, y)

N = int(2e5) + 1
p = list(range(N))

for i in range(2, N):
    if i == p[i]:
        j = i * i
        while j < N:p[j], j = i, j + i

cnt = [(N, N)] * N
num = [0] * N

for i in a:
    j = i
    t = {}

    while i > 1:
        if p[i] in t: t[p[i]] += 1
        else: t[p[i]] = 1
        i //= p[i]

    for k, v in t.items():
        num[k] += 1
        if v < cnt[k][0]: cnt[k] = (v, cnt[k][0])
        elif v < cnt[k][1]: cnt[k] = (cnt[k][0], v)
    

res = 1
for i in range(2, N):
    if i == p[i]:
        if num[i] == n - 1: res = res * i ** cnt[i][0]
        elif num[i] == n: res = res * i ** cnt[i][1]

print(res)