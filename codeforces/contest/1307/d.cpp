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

const int N = 2e5 + 7;
int n, m, k, u, d, res = 1e9 + 7, mx = 0;
queue<ii> q;
vi s(N), dis(N), din(N), isSpecial(N);
vvi g(N);
set<ii, greater<ii>> sortedSpecial;

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        isSpecial[u] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    q.push({1, 1});
    while (!q.empty()) {
        tie(u, d) = q.front();
        q.pop();
        if (dis[u]) continue;
        dis[u] = d;
        for (auto& v : g[u]) q.push({v, d + 1});
    }
    if (dis[n]) res = dis[n] - 1;
    for (int i = 1; i <= n; ++i)
        if (isSpecial[i]) sortedSpecial.insert({dis[i], i});

    q.push({n, 1});
    while (!q.empty()) {
        tie(u, d) = q.front();
        q.pop();
        if (din[u]) continue;
        din[u] = d;
        if (isSpecial[u]) {
            sortedSpecial.erase({dis[u], u});
            if (sortedSpecial.empty()) break;
            mx = max(mx, din[u] + sortedSpecial.begin()->first - 1);
        }
        for (auto& v : g[u]) q.push({v, d + 1});
    }
    res = min(res, mx);

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}