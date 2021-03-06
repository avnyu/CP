#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 3e5 + 7;
vi par(N, -1), lz(N, 0);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (-par[u] < -par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}
void solve(int T) {
    int n, m, k;
    cin >> n >> m >> k;
    set<ii> e;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        e.insert(ii{u, v});
    }
    vvi query(k, vi(3));
    for (int i = 0; i < k; ++i) {
        string s;
        int u, v;
        cin >> s >> u >> v;
        if (u > v) swap(u, v);
        query[i][0] = s[0] == 'c' ? 0 : 1;
        query[i][1] = u;
        query[i][2] = v;
        if (s[0] == 'c') e.erase(ii{u, v});
    }
    for (auto& i : e) merge(i.fi, i.se);

    vi res(k);
    int p = 0;
    for (int i = k; i--;) {
        if (query[i][0] == 0) {
            merge(query[i][1], query[i][2]);
        } else {
            res[p++] = root(query[i][1]) == root(query[i][2]);
        }
    }
    while (p--) print(res[p] ? "YES" : "NO");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

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