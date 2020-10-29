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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n, m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = min(a[i], m);
    }
    for (int i = 1; i < n; ++i) b[i] = b[i - 1] * 2 / 3;
    vector<vvi> dp(n + 1, vvi(n + 1, vi(2, -1)));
    dp[0][0][0] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (dp[i][j][0] != -1) {
                dp[i + 1][j + 1][0] =
                    max(dp[i + 1][j + 1][0], dp[i][j][0] + min(a[i], b[j]));
                dp[i + 1][max(0, j - 1)][1] =
                    max(dp[i + 1][max(0, j - 1)][1], dp[i][j][0]);
            }
            if (dp[i][j][1] != -1) {
                dp[i + 1][j + 1][0] =
                    max(dp[i + 1][j + 1][0], dp[i][j][1] + min(a[i], b[j]));
                dp[i + 1][0][1] = max(dp[i + 1][0][1], dp[i][j][1]);
            }
        }

    int res = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 2; ++j) res = max(res, dp[n][i][j]);

    print(res);

    // for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
    // for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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