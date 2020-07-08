n, k = map(int, input().split())
res = 0
cnt = [0] * (k + 1)
M = int(1e9) + 7

def pow(b, e, m):
    res = 1
    while e:
        if e & 1: res = res * b % m
        e >>= 1
        b = b * b % m
    return res

for i in reversed(range(1, k + 1)):
    t = k // i
    cnt[i] = pow(t, n, M)
    for j in range(i + i, k + 1, i):
        cnt[i] -= cnt[j]

    res = (res + cnt[i] * i) % M

print(res)