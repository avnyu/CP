for _ in range(int(input())):
    n, m, x, y = map(int, input().split())
    a = [list(input()) for _ in range(n)]

    res = 0
    for j in range(m):
        for i in range(n):
            if x + x > y and j < m - 1 and a[i][j] == '.' and a[i][j + 1] == '.':
                a[i][j] = a[i][j + 1] = '*'
                res += y
            elif a[i][j] == '.':
                res += x
    
    print(res)