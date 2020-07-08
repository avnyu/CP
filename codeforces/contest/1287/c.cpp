#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) {
        cin >> i;
        if (i == 0)
            i = -1;
        else
            i &= 1;
    }

    vector<vector<vector<vi>>> dp(n + 1, vector<vector<vi>>(n, vector<vi>(n, vi(2, 1e9))));
    int odd = (n + 1) / 2, even = n / 2, i, o, e, p;
    for (auto& i : a) {
        odd -= i == 1;
        even -= i == 0;
    }
    queue<iiii> q;

    if (a[0] == -1 && odd) {
        dp[1][odd - 1][even][1] = 1;
        q.push({1, odd - 1, even, 1});
    }
    if (a[0] == -1 && even) {
        dp[1][odd][even - 1][0] = 1;
        q.push({1, odd, even - 1, 0});
    }
    if (a[0] == 0) {
        dp[1][odd][even][0] = 1;
        q.push({1, odd, even, 0});
    }
    if (a[0] == 1) {
        dp[1][odd][even][1] = 1;
        q.push({1, odd, even, 1});
    }
    int res = 1e9;
    while (!q.empty()) {
        tie(i, o, e, p) = q.front();
        q.pop();

        if (!dp[i][o][e][p]) continue;
        // cout << i << ' ' << o << ' ' << e << ' ' << p << " -r " << dp[i][o][e][p] << '\n';
        if (i == n) {
            res = min(res, dp[i][o][e][p]);
            dp[i][o][e][p] = 0;
            continue;
        }

        if (a[i] == -1) {
            if (o) {
                dp[i + 1][o - 1][e][1] = min(dp[i + 1][o - 1][e][1], dp[i][o][e][p] + (p ^ 1));
                q.push({i + 1, o - 1, e, 1});
            }
            if (e) {
                dp[i + 1][o][e - 1][0] = min(dp[i + 1][o][e - 1][0], dp[i][o][e][p] + (p ^ 0));
                q.push({i + 1, o, e - 1, 0});
            }
        } else {
            if (a[i] == 1) {
                dp[i + 1][o][e][1] = min(dp[i + 1][o][e][1], dp[i][o][e][p] + (p ^ 1));
                q.push({i + 1, o, e, 1});
            }
            if (a[i] == 0) {
                dp[i + 1][o][e][0] = min(dp[i + 1][o][e][0], dp[i][o][e][p] + (p ^ 0));
                q.push({i + 1, o, e, 0});
            }
        }

        dp[i][o][e][p] = 0;
    }

    cout << res - 1 << '\n';
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}