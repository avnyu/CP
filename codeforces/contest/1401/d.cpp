#include <bits/stdc++.h>

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define vl vector<ll>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1e5 + 7;
const int M = 1e9 + 7;
vvi g;
vl pas, mul;

void dfs(int u) {
    pas[u] = 1;
    mul[u] = 1;
    for (auto& v : g[u])
        if (!pas[v]) {
            dfs(v);
            mul[u] += mul[v];
        }
}
void solve() {
    int n;
    cin >> n;
    g.assign(n + 1, vi());
    pas.assign(n + 1, 0);
    mul.assign(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for (int i = 2; i <= n; ++i) mul[i] = 1LL * mul[i] * (n - mul[i]);
    sort(mul.begin() + 2, mul.end());
    for (int i = 2; i <= n; ++i) mul[i] = mul[i] % M;

    int m;
    cin >> m;
    vi b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b.begin(), b.end());

    if (m >= n - 1) {
        for (int i = n - 1; i < m; ++i) b[n - 2] = 1LL * b[n - 2] * b[i] % M;

        int res = 0;
        for (int i = 2; i <= n; ++i) res = (1LL * b[i - 2] * mul[i] + res) % M;

        cout << res << '\n';
    } else {
        int res = 0;
        for (int i = n, j = m - 1; i > 1; --i, --j) {
            if (j < 0)
                res = (res + mul[i]) % M;
            else
                res = (1LL * mul[i] * b[j] + res) % M;
        }
        cout << res << '\n';
    }
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