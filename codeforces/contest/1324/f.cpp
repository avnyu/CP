#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);
template <typename T>
void print_all(vector<T>& a);

const int N = 2e5 + 7;

int n;
vi color(N), in(N), res(N);
vvi g(N);

int dfs1(int u = 1) {
    if (in[u]) return 0;
    in[u] = 1;
    res[u] = color[u] == 1 ? 1 : -1;
    for (auto& v : g[u]) res[u] += max(0, dfs1(v));
    return res[u];
}
void dfs2(int u = 1, int p = 0) {
    if (in[u]) return;
    in[u] = 1;
    res[u] += max(0, res[p] - max(0, res[u]));
    for (auto& v : g[u]) dfs2(v, u);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> color[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1();

    fill(all(in), 0);
    dfs2();

    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}