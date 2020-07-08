n = int(input())
a = [1e18] + [int(i) for i in input().split()] + [-1]

l, r = [0] * (n + 1), [0] * (n + 1)
cnt = 0
for i in range(1, n + 1):
    if a[i] <= a[i - 1]:
        cnt = 0
    cnt += 1
    l[i] = cnt

for i in reversed(range(1, n + 1)):
    if a[i] >= a[i + 1]:
        cnt = 0
    cnt += 1
    r[i] = cnt

ans = max(l)
for i in range(1, n + 1):
    if a[i - 1] < a[i + 1]:
        ans = max(ans, l[i - 1] + r[i + 1])

print(ans)