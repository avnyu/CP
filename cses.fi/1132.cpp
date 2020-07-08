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
template <typename T>
void print_all(vector<T>& a);

const int N = 2e5 + 1;
int n;
vi hf(N - 1), vf(N, -1), hs(N, -1), vs(N, -1);
vvi g(N);

void change(int u, int l, int v) {
    if (l > hf[u])
        hs[u] = hf[u], vs[u] = vf[u], hf[u] = l, vf[u] = v;
    else if (l > hs[u])
        hs[u] = l, vs[u] = v;
}

int dfs(int u = 1, int p = 0) {
    for (auto& v : g[u])
        if (v != p) change(u, dfs(v, u) + 1, v);

    return hf[u];
}

void dfs2(int u = 1, int p = 0) {
    if (p) {
        if (u != vf[p]) change(u, hf[p] + 1, p);
        if (u != vs[p]) change(u, hs[p] + 1, p);
        // write("dfs2", u, p, vf[u]);
    }

    for (auto& v : g[u])
        if (v != p) dfs2(v, u);
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();

    dfs2();

    for (int i = 1; i <= n; ++i) cout << hf[i] << " \n"[i == n];
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