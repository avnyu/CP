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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

int n;
vi l, r, in;
vvi g;
vector<vector<ll>> dp;

void dfs(int u = 0) {
    in[u] = 1;
    for (auto& v : g[u]) {
        if (in[v]) continue;
        dfs(v);
        dp[u][0] +=
            max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] +=
            max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
    }
}
void solve() {
    cin >> n;
    g.assign(n, vi());
    l.assign(n, 0);
    r.assign(n, 0);
    dp.assign(n, vector<ll>(2, 0));
    in.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    print(max(dp[0][0], dp[0][1]));
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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