#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvll vector<vector<ll>>
#define vl vector<ll>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e5 + 7;
const int M = 1e9 + 2;
vvi g;
vl p(N), h(N), pas(N), cnt(N), sum(N);

bool dfs(int u) {
    pas[u] = 1;
    bool ok = true;
    sum[u] = p[u];
    for (auto& v : g[u])
        if (!pas[v]) {
            ok &= dfs(v);
            sum[u] += sum[v];
            cnt[u] += h[v];
        }
    if ((h[u] + sum[u] + M) % 2 == 1) ok = false;
    h[u] = (sum[u] - h[u]) / 2;
    if (h[u] < 0 || h[u] > sum[u]) ok = false;
    if (cnt[u] < h[u] - p[u]) ok = false;
    // cout << u << " " << sum[u] << " " << p[u] << " " << h[u] << " " << cnt[u] << '\n';

    return ok;
}
void solve() {
    int n, m;
    cin >> n >> m;
    sum.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    pas.assign(n + 1, 0);
    g.assign(n + 1, vi());
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << (dfs(0) ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}