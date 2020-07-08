for _ in range(int(input())):
    n, k = map(int, input().split())

    l, r, x = 0, int(2e9), 0
    while l <= r:
        m = l + r >> 1
        if m * (n - 1) < k:
            x = m * n
            l = m + 1
        else:
            r = m - 1

    print(x + k % (n - 1) + (n - 1) * (k % (n - 1) == 0))
