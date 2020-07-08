q = int(input())
for tc in range(q):
    a, b, c = [int(i) for i in input().split()]
    ans = 1e18
    for ai in range(-1, 2):
        for bi in range(-1, 2):
            for ci in range(-1, 2):
                ans = min(ans, abs(a + ai - b - bi) + abs(a + ai - c - ci) + abs(b + bi - c - ci))
    print(ans)