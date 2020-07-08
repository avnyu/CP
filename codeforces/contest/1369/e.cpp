#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e5 + 1;
int n, m;
vi num(N);
vii edges;
vvi g(N);

void solve() {
    cin >> n >> m;
    for (int i = 0; i++ < n;) cin >> num[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(edges.size());
        g[v].push_back(edges.size());
        edges.push_back({u, v});
        num[u]--;
        num[v]--;
    }
    vi res;
    priority_queue<int> pq;
    for (int i = 0; i++ < n;)
        if (num[i] > -1) pq.push(i);

    while (pq.size()) {
        int u = pq.top(), v, p;
        pq.pop();

        if (g[u].empty()) continue;

        while (1) {
            p = g[u].back();
            g[u].pop_back();

            if (edges[p].fi != -1) break;
            if (g[u].empty()) break;
        }

        if (edges[p].fi == -1) continue;
        res.push_back(p);

        tie(u, v) = edges[p];
        edges[p].fi = -1;

        num[u]++;
        num[v]++;
        if (num[u] > -1) pq.push(u);
        if (num[v] > -1) pq.push(v);
    }

    if (m == res.size()) {
        print("ALIVE");
        for (int i = m; i--;) cout << res[i] + 1 << " \n"[!i];
    } else {
        print("DEAD");
        // for (int i = res.size(); i--;) cout << res[i] + 1 << " \n"[!i];
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

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    cout << x << ' ';
    print(args...);
}
