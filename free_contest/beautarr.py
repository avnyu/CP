n = int(input())
a = [int(i) for i in input().split()]

cnt = [0] * 500005
j = 0
ans = 0

for i in range(n):
    while j < n and cnt[a[j]] < 2:
        cnt[a[j]] += 1
        j += 1
    ans += j - i
    cnt[a[i]] -= 1

print(ans)
