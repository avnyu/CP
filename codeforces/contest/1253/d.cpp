#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int N = 2e5 + 7;
int n, m, res = 0;
vector<vector<int>> graph(N);
vector<int> in(N), par(N, -1), upper(N);

int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }
int merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return 0;
    if (u > v) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    upper[u] = max(upper[u], upper[v]);

    return 1;
}

void init() {
    for (int i = 0; i < N; ++i) upper[i] = i;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    int i = 0;
    while (i <= n) {
        int j = i;
        while (j < upper[i]) {
            int k = merge(i, j);
            res += k;
            j++;
        }

        i = j + 1;
    }
    cout << res << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    init();
    solve();

    return 0;
}