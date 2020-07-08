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

const int N = 100001;
vvi g(N);
vi in(N), deg(N), h(N);
int mn = 1, mx = 0;

int dfs(int u) {
    if (deg[u] == 1) return h[u] = 1;
    in[u] = 1;
    for (auto& v : g[u])
        if (!in[v]) h[u] = max(h[u], dfs(v));
    return h[u] = h[u] + 1;
}
void dfsmin(int u) {
    if (deg[u] == 1) return;
    in[u] = 1;
    vector<bool> t(2, false);
    for (auto& v : g[u])
        if (!in[v]) {
            dfsmin(v);
            t[h[v] & 1] = true;
        }
    if (t[0] && t[1]) mn = 3;
}
int dfsmax(int u) {
    if (deg[u] == 1) return 0;
    in[u] = 1;
    vi t(2, 0);
    for (auto& v : g[u])
        if (!in[v]) t[dfsmax(v)]++;
    mx += (t[0] > 0) + t[1];
    return 1;
}
void solve() {
    int n;
    cin >> n;
    vii a(n - 1);
    for (auto& i : a) {
        cin >> i.fi >> i.se;
        g[i.fi].emplace_back(i.se);
        g[i.se].emplace_back(i.fi);
        deg[i.fi]++;
        deg[i.se]++;
    }
    int r;
    for (int i = 0; i++ < n;)
        if (deg[i] > 1) {
            r = i;
            break;
        }

    fill(all(in), 0);
    dfs(r);
    fill(all(in), 0);
    dfsmin(r);
    fill(all(in), 0);
    dfsmax(r);

    write(mn, mx);
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