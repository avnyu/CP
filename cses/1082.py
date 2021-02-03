n = int(input())

N = int(1e6) + 1
M = int(1e9) + 7
res = 0

for i in range(1, N):
    res += n // i * i % M
    res %= M

for i in range(1, N):
    l = n // (i + 1)
    r = n // i

    l = max(l, N - 1)
    r = max(r, N - 1)

    t = r * (r + 1) // 2 - l * (l + 1) // 2
    t %= M

    res += i * t % M
    res %= M

print(res)
