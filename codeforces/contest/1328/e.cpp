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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int N = 1 << 18;
const int logN = 18;
vvi g(N), par(N, vi(logN, -1));
vi check(N), hgt(N), p2(logN);

void dfs(int u, int p, int h = 1) {
    if (hgt[u]) return;
    hgt[u] = h;
    par[u][0] = p;
    for (auto& v : g[u]) dfs(v, u, h + 1);
}
void lca_init() {
    p2[0] = 1;
    for (int i = 1; i < logN; ++i) p2[i] = p2[i - 1] << 1;
    for (int i = 1; i < logN; ++i)
        for (int j = 0; j < N; ++j)
            if (par[j][i - 1] != -1) par[j][i] = par[par[j][i - 1]][i - 1];
}
int lca(int u, int v) {
    if (hgt[u] > hgt[v]) swap(u, v);
    for (int i = logN; i--;)
        if (hgt[v] - p2[i] >= hgt[u]) {
            v = par[v][i];
        }
    if (u == v) return u;
    for (int i = logN; i--;)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
int ances(int u, int h) {
    for (int i = logN; i--;)
        if (hgt[u] - p2[i] >= h) u = par[u][i];
    return u;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    lca_init();
    vi query(N);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int lowp, lowh = -1;
        for (int j = 0; j < k; ++j) {
            int& x = query[j];
            cin >> x;
            if (hgt[x] > lowh) {
                lowp = x;
                lowh = hgt[x];
            }
        }
        bool ok = true;
        for (int j = 0; j < k; ++j) {
            int& u = query[j];
            if (ances(lowp, hgt[u] - 1) != par[u][0]) ok = false;
        }
        write(ok ? "YES" : "NO");
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
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}