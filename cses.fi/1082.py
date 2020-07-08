n = int(input())

N = 5
M = int(1e9) + 7
res = 0

for i in range(1, N):
    res += n // i * i % M
    res %= M

    print('th1 {} {}'.format(i, n // i))

for i in range(1, N):
    l = n // (i + 1)
    r = n // i

    l = max(l, N - 1)
    r = max(r, N - 1)

    t = r * (r + 1) // 2 - l * (l + 1) // 2
    t %= M

    res += i * t % M
    res %= M

    print('th2 {} {} {}'.format(i, l, r))

print(res)