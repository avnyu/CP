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
    int n, m;
    cin >> n >> m;
    ll bal[n + 1] = {};
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        bal[u] += w;
        bal[v] -= w;
    }

    vector<vector<ll>> res(3e5 + 7, vector<ll>(3));
    int lres = 0;
    int in = 0, ip;
    for (ip = 1; ip <= n; ++ip) {
        if (bal[ip] <= 0) continue;
        while (bal[ip]) {
            while (in < n && bal[in] >= 0) in++;
            ll x = min(-bal[in], bal[ip]);
            bal[ip] -= x;
            bal[in] += x;
            res[lres][0] = ip;
            res[lres][1] = in;
            res[lres][2] = x;
            lres++;
        }
    }
    cout << lres << '\n';
    for (int i = 0; i < lres; ++i)
        for (int j = 0; j < 3; ++j) cout << res[i][j] << " \n"[j == 2];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}