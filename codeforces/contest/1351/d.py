for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    p = 0
    i, j = -1, n
    s1, s2 = 0, 0
    c = 0

    while i < j - 1:
        s = 0
        if i < j - 1: c += 1
        while i < j - 1 and s <= p:
            i += 1
            s += a[i]

        s1 += s
        p = s

        s = 0
        if j > i + 1: c += 1
        while j > i + 1 and s <= p:
            j -= 1
            s += a[j]

        s2 += s
        p = s

    print(c, s1, s2)
