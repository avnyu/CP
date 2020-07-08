n = int(input())
s = input()

cnt = [[0, 0, 0] for _ in range(n)]

for i in range(n):
    cnt[i][0 if s[i] == 'R' else 1 if s[i] == 'G' else 2] += 1
    if i:
        for j in range(3):
            cnt[i][j] += cnt[i - 1][j]

res = 0
for i in range(1, n):
    for j in range(i + 1, n):
        if s[i] == s[j]: continue
        if s[i] != 'R' and s[j] != 'R':
            res += cnt[i - 1][0]
            if i + i - j >= 0: res -= s[i + i - j] == 'R'
        if s[i] != 'G' and s[j] != 'G':
            res += cnt[i - 1][1]
            if i + i - j >= 0: res -= s[i + i - j] == 'G'
        if s[i] != 'B' and s[j] != 'B':
            res += cnt[i - 1][2]
            if i + i - j >= 0: res -= s[i + i - j] == 'B'

print(res)