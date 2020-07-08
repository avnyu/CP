t = int(input())
for tc in range(t):
    n = int(input())
    s = ['C'] * n
    
    a = [list(map(int, input().split())) for _ in range(n)]
    a = [a[i] + [i] for i in range(n)]
    a = sorted(a)
    
    p = 0
    for i in range(n):
        if a[i][0] >= p:
            s[a[i][2]] = 'J'
            p = a[i][1]
    p = 0
    for i in range(n):
        if s[a[i][2]] == 'C':
            if a[i][0] < p:
                p = -1
                break
            p = a[i][1]
    
    print('Case #{}: {}'.format(tc + 1, 'IMPOSSIBLE' if p == -1 else ''.join(s)))