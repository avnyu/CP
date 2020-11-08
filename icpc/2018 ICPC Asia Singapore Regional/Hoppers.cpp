#include <bits/stdc++.h>
#define lli long long int
using namespace std;

const int N = 5e5 + 7;
int n, m, res = 0;
vector<int> par(N, -1), hgt(N, 0);
vector<vector<int>> g(N);

int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }
int merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return 0;
    par[u] += par[v];
    par[v] = u;
    return 1;
}

int dfs(int u, int p, int h) {
    if (hgt[u]) return (hgt[u] & 1) ^ (h & 1);
    hgt[u] = h;

    int res = 0;
    for (auto& v : g[u]) res |= dfs(v, u, h + 1);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (hgt[i]) continue;
        res |= dfs(i, 0, 1);
    }

    res = n - res;
    for (int i = 1; i < n; ++i)
        for (auto& j : g[i]) res -= merge(i, j);

    cout << res << '\n';

    return 0;
}
