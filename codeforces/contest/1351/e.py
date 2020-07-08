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

    print(res)
