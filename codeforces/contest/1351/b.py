for _ in range(int(input())):
    n, k = map(int, input().split())

    t1 = n - (k - 1)
    t2 = n - (k - 1) * 2

    if t1 > 0 and t1 & 1:
        print('YES')
        print(' '.join([str(i) for i in ([1 for _ in range(k - 1)] + [t1])]))
        continue

    if t2 > 0 and t2 & 1 == 0:
        print('YES')
        print(' '.join([str(i) for i in ([2 for _ in range(k - 1)] + [t2])]))
        continue

    print('NO')
