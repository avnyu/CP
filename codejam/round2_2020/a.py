from sys import stdin, stdout

save = [[] for _ in range(2001)]


def cald(n):
    l, r, x = 0, int(2e9), 0
    while l <= r:
        m = l + r >> 1
        if (m * (m + 1) >> 1) > n: r = m - 1
        else: l, x = m + 1, m
    return x


def cal1(n):
    if n & 1 == 0: n -= 1
    return (1 + n) // 2 * (n + 1) // 2


def cal2(n):
    if n & 1: n -= 1
    return (2 + n) // 2 * n // 2


def cal(l, r, n, m):
    t1 = cal1(m) - cal1(n)
    t2 = cal2(m) - cal2(n)
    
    if l >= r and n & 1 == 0: return l - t1, r - t2
    if l < r and n & 1: return l - t1, r - t2
    return l - t2, r - t1

for tc in range(int(input())):
    l, r = map(int, input().split())
    n = 0

    n = cald(abs(l - r))
    if l >= r: l -= n * (n + 1) >> 1
    else: r -= n * (n + 1) >> 1

    lef, rig, m = 0, int(2e9), 0

    while lef <= rig:
        mid = lef + rig >> 1
        nl, nr = cal(l, r, n, mid)
        if nl >= 0 and nr >= 0:
            m, lef = mid, mid + 1
        else:
            rig = mid - 1

    l, r = cal(l, r, n, m)
    print('Case #{}: {} {} {}'.format(tc + 1, m, l, r))

