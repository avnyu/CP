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

    int n, p = 0, q;
    cin >> n;
    int nn = n + n + 7;
    vector<vector<double>> dp(2, vector<double>(nn));
    dp[0][n] = dp[1][n] = 1.0;
    for (int t = 0; t < n; ++t) {
        double pi;
        cin >> pi;
        p = 1 - p, q = 1 - p;

        for (int i = 0; i < nn; ++i) dp[q][i] = 0;
        for (int i = 0; i < nn; ++i) {
            if (i) dp[q][i - 1] += (-pi + 1.0) * dp[p][i];
            if (i < nn - 1) dp[q][i + 1] += pi * dp[p][i];
        }
        // for (int i = 0; i < nn; ++i) cout << dp[q][i] << " \n"[i == nn - 1];
    }
    double res = 0;
    for (int i = n + 1; i < nn; ++i) res += dp[q][i];
    cout << fixed << setprecision(18) << res << '\n';

    return 0;
}