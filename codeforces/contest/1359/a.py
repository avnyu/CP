for _ in range(int(input())):
    n, m, k = map(int, input().split())
    t = min(n // k, m)
    print(t - (m - t) // (k - 1) - ((m - t) % (k - 1) > 0))