#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    const int N = 507;

    int n, m, r;
    cin >> n >> m >> r;

    vector<string> s(N);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<vector<int>> t(N, vector<int>(N, N));
    for (int i = 0; i < n; ++i) {
        for (int j = 0, sk1 = 0; j < m; ++j) {
            for (int k = m - 1, sk2 = 0; k >= j; --k) {
                t[i][sk1 + sk2] = min(t[i][sk1 + sk2], k - j + 1);
                if (s[i][k] == '1') sk2++;
            }
            if (s[i][j] == '1') sk1++;
            if (j == m - 1) t[i][sk1] = min(t[i][sk1], 0);
        }
    }

    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < m; ++j) cout << i << " " << j << " " << t[i][j] << '\n';

    vector<vector<int>>dp(N, vector<int>(N, N * N));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j <= r; ++j)
            for (int k = 0; j + k <= r; ++k)
                dp[i + 1][j + k] = min(dp[i + 1][j + k], dp[i][j] + t[i][k]);

    int res = N * N;
    for (int i = 0; i <= r; ++i)res = min(res, dp[n][i]);

    cout << res << '\n';

    return 0;
}