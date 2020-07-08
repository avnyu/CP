for _ in range(int(input())):
    x1, y1, x2, y2 = map(int, input().split())
    t1 = x2 - x1 + 1
    t2 = y2 - y1 + 1
    t = min(t1, t2)
    sum1n = lambda n: n * (n + 1) // 2

    k = t1 + t2 - 1 - t - t
    ans = sum1n(t) * 2 + k * t
    print(1 + ans - t1 - t2 + 1)