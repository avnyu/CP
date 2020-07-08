s, t = input(), input()

n, m = len(s), len(t)
N, M = 207, int(1e9) + 7

dp = [[[M for i in range(N)] for j in range(m + 1)] for k in range(n + 1)]
pr = [[[M for i in range(N)] for j in range(m + 1)] for k in range(n + 1)]

s += '.'
t += '.'

dp[0][0][0] = 0
for i in range(0, n + 1):
    for j in range(0, m + 1):
        for k in range(N):
            if dp[i][j][k] == M:
                continue

            ni = i + (s[i] == '(')
            nj = j + (t[j] == '(')
            if k < N - 1 and dp[ni][nj][k + 1] > dp[i][j][k] + 1:
                dp[ni][nj][k + 1] = dp[i][j][k] + 1
                pr[ni][nj][k + 1] = ni - i + (nj - j) * 2 + 4

            ni = i + (s[i] == ')')
            nj = j + (t[j] == ')')
            if k and dp[ni][nj][k - 1] > dp[i][j][k] + 1:
                dp[ni][nj][k - 1] = dp[i][j][k] + 1
                pr[ni][nj][k - 1] = ni - i + (nj - j) * 2

k = M

for i in range(N):
    k = min(k, dp[n][m][i] + i)

for i in range(N):
    if k == dp[n][m][i] + i:
        k = i
        break

# for i in range(13):
#     print(n, m, i, dp[n][m][i], pr[n][m][i])

res = ''.join(')' for t in range(k))
while n or m or k:
    # print(n, m, k)
    nn, nm, nk = n, m, k

    if pr[n][m][k] & 4:
        res += '('
        nk -= 1
    else:
        res += ')'
        nk += 1

    if pr[n][m][k] & 2:
        nm -= 1

    if pr[n][m][k] & 1:
        nn -= 1

    n, m, k = nn, nm, nk

res = ''.join(reversed(res))
print(res)