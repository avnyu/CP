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

int n, m, res, N = 1e5 + 7;
vector<vector<int>> g(N);
vector<int> h(N);

int dfs(int u) {
    if (h[u]) return h[u];
    h[u] = 1;
    for (auto& v : g[u]) h[u] = max(h[u], 1 + dfs(v));
    return h[u];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 0; i++ < n;) dfs(i);
    sort(h.begin(), h.end());
    cout << h.back() - 1 << '\n';

    return 0;
}