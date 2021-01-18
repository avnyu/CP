#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // dp[i][j][k]: i = state, j = no bugs, k = programmer k currently coding
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(1007, vector<int>(507, 0)));
    dp[0][0][0] = 1;

    int n, m, b, M;
    cin >> n >> m >> b >> M;

    vector<int> a(507);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= b; ++j)
            for (int k = 0; k < n; ++k) dp[(i & 1) ^ 1][j][k] = 0;

        for (int j = 0; j <= b; ++j)
            for (int k = 0, sum = 0; k < n; ++k) {
                auto &cur = dp[i & 1][j][k];
                auto &nxt = dp[(i & 1) ^ 1][j + a[k]][k];

                sum = (sum + cur) % M;
                nxt = (nxt + sum) % M;
            }
    }

    int res = 0;
    for (int i = 0; i <= b; ++i)
        for (int j = 0; j < n; ++j) res = (res + dp[m & 1][i][j]) % M;

    cout << res << '\n';

    return 0;
}