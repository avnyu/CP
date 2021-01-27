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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vvll a(n + 1, vll(m));
    for (int i = 1; i <= n; ++i) cin >> a[i][0];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m && i + j <= n; ++j)
            a[i][j] = a[i][j - 1] + a[i + j][0];

    vll dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0 && i - j <= m; --j)
            dp[i] = max(dp[i], dp[j] + a[j + 1][i - j - 1] - k);
    }
    cout << (*max_element(dp.begin(), dp.end())) << '\n';

    // for (int i = 0; i <= n; ++i) cout << dp[i] << " \n"[i == n];
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