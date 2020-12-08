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

void solve() {
    int n, M = 1e9 + 7;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (auto& i : a)
        for (auto& j : i) cin >> j;

    vector<int> dp(1 << n), cnt(1 << n), step(1 << n);
    dp[0] = 1;

    int s = 0, t = 1;
    while (s + 1 < (1 << n)) {
        int msk = step[s++], i = cnt[msk];

        if (i == n) break;

        for (int j = 0; j < n; ++j) {
            if (a[i][j] && !(msk & (1 << j))) {
                if (!cnt[msk | (1 << j)]) {
                    step[t++] = msk | (1 << j);
                    cnt[msk | (1 << j)] = cnt[msk] + 1;
                }
                dp[msk | (1 << j)] = (dp[msk | (1 << j)] + dp[msk]) % M;
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
