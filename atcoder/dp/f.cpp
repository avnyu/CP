#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n + 1][m + 1] = {};

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (i < n && j < m && s[i] == t[j] && dp[i][j] + 1 > dp[i + 1][j + 1]) dp[i + 1][j + 1] = dp[i][j] + 1;
            if (i < n && dp[i][j] > dp[i + 1][j]) dp[i + 1][j] = dp[i][j];
            if (j < m && dp[i][j] > dp[i][j + 1]) dp[i][j + 1] = dp[i][j];
        }
    string res = "";
    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j <= m; ++j) cout << dp[i][j] << " \n"[j == m];
    while (n || m) {
        if (n && m && s[n - 1] == t[m - 1] && dp[n][m] == dp[n - 1][m - 1] + 1) {
            --n, --m;
            res += s[n];
        } else if (n && dp[n][m] == dp[n - 1][m])
            --n;
        else
            --m;
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';

    return 0;
}