#include <bits/stdc++.h>
using namespace std;

int n, m, b, M;
int a[501];
int dp[501][501][501];

int dfs(int p, int l, int t) {
    if (p == 0) return l == 0 ? 1 : 0;
    if (dp[p][l][t] != -1) return dp[p][l][t];

    dp[p][l][t] = 0;
    for (int i = 0; i <= l && a[p] * i <= t; ++i)
        dp[p][l][t] = (dp[p][l][t] + dfs(p - 1, l - i, t - a[p] * i)) % M;

    return dp[p][l][t];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> b >> M;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    cout << dfs(n, m, b) << '\n';

    return 0;
}