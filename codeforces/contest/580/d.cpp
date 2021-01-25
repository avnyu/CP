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
#define vvl vector<vl>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n, m, kk;
    cin >> n >> m >> kk;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vvi r(n, vi(n));
    for (int i = 0; i < kk; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        r[u - 1][v - 1] = c;
    }
    vvl dp(1 << n, vl(n, -1));
    for (int i = 0; i < n; ++i) dp[1 << i][i] = a[i];

    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j)
            if ((i & (1 << j)) > 0 && dp[i][j] != -1)
                for (int k = 0; k < n; ++k)
                    if ((i & (1 << k)) == 0)
                        dp[i + (1 << k)][k] =
                            max(dp[i + (1 << k)][k], dp[i][j] + r[j][k] + a[k]);
    }

    ll res = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j)) cnt++;
        if (cnt == m)
            for (int j = 0; j < n; ++j) res = max(res, dp[i][j]);
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
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