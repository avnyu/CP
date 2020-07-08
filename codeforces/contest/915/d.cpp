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
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

const int N = 507, M = 2e5 + 7;
int n, m, j;
vi in(N), par(N);
vi cycle(N);
vvi g(N, vi(N));

bool dfs(int u = 0) {
    if (in[u]) return par[u] == 0;
    in[u] = 1;
    par[u] = 1;
    for (int v = 1; v <= n; ++v)
        if (g[u][v] && !dfs(v)) {
            par[u] = 0;
            return false;
        }
    par[u] = 0;
    return true;
}
void get(int u = 0) {
    // cout << u << '\n';
    if (in[u]) {
        if (par[u]) {
            cycle[j++] = u;
            // cout << j - 1 << ' ' << u << '\n';
        }
        return;
    }
    in[u] = 1;
    par[u] = 1;
    for (int v = 1; v <= n; ++v)
        if (g[u][v]) {
            get(v);
            if (cycle[0]) break;
        }
    if (cycle[0]) {
        cycle[j++] = u;
        // cout << j - 1 << ' ' << u << '\n';
    }
    par[u] = 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
    }
    for (int i = 1; i <= n; ++i) g[0][i] = 1;
    // g[2][3] = 0;
    if (dfs()) {
        cout << "YES\n";
        return;
    }
    fill(all(in), 0);
    fill(all(par), 0);
    get();
    for (int i = 1; i < N; ++i) {
        fill(all(in), 0);
        fill(all(par), 0);
        g[cycle[i]][cycle[i - 1]] = 0;
        if (dfs()) {
            cout << "YES\n";
            return;
        }
        g[cycle[i]][cycle[i - 1]] = 1;
        if (cycle[i] == cycle[0]) break;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}