#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) (ll) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

const int N = 5e3 + 7;

int n, m;
vector<vector<ii>> g(N);
vi pas(N), res(N);
vvi save(N, vi(3));

int dfs(int u, int e, int x) {
    if (pas[u]) return 0;
    pas[u] = 1;
    if (u == e) return pas[u] = 1;

    for (auto& ev : g[u]) {
        int v = ev.fi, i = ev.se;
        if (dfs(v, e, x)) {
            res[i] = max(res[i], x);
            return x;
        }
    }
    return 0;
}

int chk(int u, int e) {
    if (pas[u]) return 0;
    pas[u] = 1;
    if (u == e) return 1e6;

    for (auto& ev : g[u]) {
        int v = ev.fi, i = ev.se, x = chk(v, e);
        if (x) return min(x, res[i]);
    }
    return 0;
}

void solve() {
    cin >> n;
    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    cin >> m;
    rep(i, 0, m) {
        int u, v, x;
        cin >> u >> v >> x;
        save[i] = {u, v, x};
        dfs(u, v, x);
        fill(all(pas), 0);
    }
    rep(i, 1, n) if (res[i] == 0) res[i] = 1e6;
    rep(i, 0, m) {
        if (chk(save[i][0], save[i][1]) != save[i][2]) {
            cout << "-1\n";
            return;
        }
        fill(all(pas), 0);
    }
    rep(i, 1, n) cout << res[i] << " \n"[i == n - 1];
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}