#include <bits/stdc++.h>

using namespace std;

int n, k, p;
int dp[20002][52][102];
int a[20002];

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n >> k >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];

    a[n] = 0;
    memset(dp, -1, sizeof dp);
    dp[1][1][a[0] % p] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            for (int l = 0; l < p; ++l)
                if (dp[i][j][l] != -1) {
                    auto &cur = dp[i][j][l];
                    auto &nxt1 = dp[i + 1][j + 1][a[i] % p];
                    auto &nxt2 = dp[i + 1][j][(l + a[i]) % p];

                    nxt1 = max(nxt1, cur + l);
                    nxt2 = max(nxt2, cur);
                }

    cout << dp[n + 1][k + 1][0] << '\n';

    return 0;
}