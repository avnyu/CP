#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, b, M;
    cin >> n >> m >> b >> M;

    int a[502];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int dp[2][1004][502];
    memset(dp, 0, sizeof dp);
    cout << "Sdf\n";

    dp[0][0][0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= b; ++j)
            for (int k = 0; k < n; ++k) dp[(i & 1) ^ 1][j][k] = 0;

        for (int j = 0; j < b; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                auto &cur = dp[i & 1][j][k];
                auto &nxt = dp[(i & 1) ^ 1][j + a[k]][k];

                sum = (sum + cur) % M;
                nxt = (nxt + sum) % M;
            }
        }
    }

    cout << "Sdf\n";

    int res = 0;
    for (int i = 0; i <= b; ++i)
        for (int j = 0; j < n; ++j) res = (res + dp[m & 1][i][j]);

    cout << res << '\n';

    return 0;
}