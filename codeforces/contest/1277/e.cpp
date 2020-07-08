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

int n, m, a, b;
vector<vector<int>> g;
vector<int> par, in;

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    par[u] = -((-par[u]) | (-par[v]));
    par[v] = u;
}
void add(int u, int x) {
    u = root(u);
    par[u] = -((-par[u]) | x);
}

void dfs(int u) {
    in[u] = 1;
    for (auto& v : g[u]) {
        if (!in[v]) {
            if (v == a)
                add(u, 2);
            else if (v == b)
                add(u, 4);
            else {
                merge(u, v);
                dfs(v);
            }
        }
    }
}

void solve() {
    g.clear();
    cin >> n >> m >> a >> b;
    g.resize(n + 1);
    par.assign(n + 1, -1);
    in.assign(n + 1, 0);
    par[a] = -3;
    par[b] = -5;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!in[i] && i != a && i != b) dfs(i);

    int cnta = 0, cntb = 0;
    for (int i = 1; i <= n; ++i) {
        if (par[root(i)] == -3) cnta++;
        if (par[root(i)] == -5) cntb++;
    }
    //for (int i = 1; i <= n; ++i) cout << par[root(i)] << '\n';

    cout << 1LL * (cnta - 1) * (cntb - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}