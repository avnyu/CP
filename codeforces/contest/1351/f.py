for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    cnt = [0] * 8008
    for i in a:
        cnt[i] += 1

    t = a.copy()
    for i in range(1, n):
        t[i] += t[i - 1]

    res = 0
    for i in range(n):
        for j in range(i + 1, n):
            if t[j] < 8008:
                res += cnt[t[j]]
                cnt[t[j]] = 0
        for j in range(i + 1, n):
            t[j] -= a[i]

for _ in range(int(input())):
    a, b, c = map(int, input().split())

    x = ''.join(['0'] * (a + 1))
    z = ''.join(['1'] * (c + 1))

    if b == 0:
        if a:
            print(x)
            continue
        if c:
            print(z)
            continue

    y = ''
    b -= 1

    while b > 1:
        y += '10'
        b -= 2

    t = x + y + z

    if b: t += '0'

    print(t)
