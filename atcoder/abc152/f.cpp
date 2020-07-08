#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1 << 20, N = 51;
int n, m;
vi edge_bit(N), in(N);
vector<ll> dp(M);
vector<vector<ii>> g(N);

int edge_set(int u, int e, int j) {
    if (u == e) return 1;
    if (in[u]) return 0;
    in[u] = 1;
    for (auto ev : g[u]) {
        int v = ev.fi, i = ev.se;
        if (edge_set(v, e, j)) {
            if (u > v) swap(u, v);
            edge_bit[i] |= (1 << j);
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        g[u].eb(ii{v, i});
        g[v].eb(ii{u, i});
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        in.assign(N, 0);
        edge_set(u, v, i);
    }
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
        for (int msk = (1 << m) - 1; msk >= 0; --msk)
            dp[msk | edge_bit[i]] += dp[msk];

    cout << dp[(1 << m) - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}