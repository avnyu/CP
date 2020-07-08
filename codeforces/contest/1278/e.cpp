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

int p = 1, N = 5e5 + 7, n;
vector<vector<int>> g(N);
vector<int> in(N, 0);
vector<ii> res(N);

void dfs(int u) {
    in[u] = 1;
    for (int i = g[u].size(); i--;) {
        int v = g[u][i];
        if (!in[v]) {
            res[v].fi = p++;
        }
    }
    res[u].se = p++;
    for (auto& v : g[u])
        if (!in[v]) dfs(v);
}

void solve() {
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    res[1].fi = p++;
    dfs(1);

    for (int i = 1; i <= n; ++i) cout << res[i].fi << ' ' << res[i].se << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}