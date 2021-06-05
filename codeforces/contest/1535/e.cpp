#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

int K = 20;
int N = 3e5 + 7;

vvi par(N, vi(K));
vi gold(N), cost(N);
vll sum_gold(N), full_cost(N), used(N);

void add(int u, int p, int g, int c) {
    gold[u] = g;
    cost[u] = c;
    par[u][0] = p;

    sum_gold[u] = sum_gold[p] + gold[u];
    full_cost[u] = full_cost[p] + 1LL * cost[u] * gold[u];

    for (int j = 1; j < K; ++j) par[u][j] = par[par[u][j - 1]][j - 1];
}
pair<ll, ll> get(int u, ll w) {
    ll v, e, x, a;

    e = u;
    for (int j = K; j--;)
        if (used[par[e][j]] == 0) e = par[e][j];
    if (used[e] == 0) e = par[e][0];

    for (int j = K; j--;)
        if (sum_gold[par[u][j]] - used[e] >= w) u = par[u][j];

    x = min(sum_gold[u] - used[e], w);
    a = full_cost[u] - cost[u] * (sum_gold[u] - x - used[e]);
    a = a - (full_cost[e] - cost[e] * (sum_gold[e] - used[e]));

    used[u] = x + used[e];
    if (u != par[u][0])
        for (v = par[u][0]; used[v] != sum_gold[v]; v = par[v][0])
            used[v] = sum_gold[v];

    return make_pair(x, a);
}
void solve() {
    int q, g, c, p, v, w, t;
    cin >> q >> g >> c;
    add(0, 0, g, c);

    for (int i = 1; i <= q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> p >> g >> c;
            add(i, p, g, c);
        } else {
            cin >> v >> w;
            pair<ll, ll> ans = get(v, w);
            cout << ans.fi << " " << ans.se << endl;
        }
    }

    prt(used.begin(), used.begin() + 8);
}
int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve();

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