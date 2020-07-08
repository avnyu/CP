def pos(t, a, n, x, y):
    print('Case #{}: POSSIBLE'.format(t + 1))
    for i in range(n):
        print(' '.join([str(a[i][j]) for j in range(n)))


def solve(t):
    n, k = map(int, input().split())
    a = [[(i + j) % n + 1 for j in range(n)] for i in range(n)]

    for x in range(n):
        for y in range(n):
            if sum([a[i][i] for i in range(n)]) == k:
                pos(t, a, n)
                return
            


T = int(input())
for t in range(T):
    solve(t)