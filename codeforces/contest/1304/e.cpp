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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

const int N = 1e5 + 7;
const int logN = 20;
int n;
vi h(N);
vvi g(N),   st(N, vi(logN, -1));

void find_par(int u, int p, int hu) {
    if (h[u]) return;
    h[u] = hu;
    st[u][0] = p;
    for (auto& v : g[u]) find_par(v, u, hu + 1);
}
void st_init() {
    for (int i = 1; i < logN; ++i)
        for (int j = 1; j <= n; ++j)
            if (st[j][i - 1] != -1) st[j][i] = st[st[j][i - 1]][i - 1];
}
int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = logN; i--;)
        if (h[u] - (1 << i) >= h[v]) u = st[u][i];
    if (u == v) return u;
    for (int i = logN; i--;)
        if (h[u] >= (1 << i) && st[u][i] != st[v][i])
            u = st[u][i], v = st[v][i];
    return st[u][0];
}

int len(int u, int v) {
    int a = lca(u, v);
    return h[u] - h[a] + h[v] - h[a];
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    find_par(1, -1, 1);
    st_init();

    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int p1 = len(a, b);
        int p2 = 1 + min(len(a, x) + len(b, y), len(a, y) + len(b, x));
        if (((p1 ^ k) & 1) == 0 && p1 <= k)
            cout << "YES\n";
        else if (((p2 ^ k) & 1) == 0 && p2 <= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}