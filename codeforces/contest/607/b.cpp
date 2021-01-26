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
    int n;
    cin >> n;
    vi c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    vvi dp(n + 1, vi(n + 1, n));

    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < n + 1; ++j)
            if (i > j) dp[i][j] = 0;

    for (int l = 0; l < n; ++l)
        for (int i = 0, j = l; j < n; ++i, ++j) {
            if (i == j)
                dp[i][j] = 1;
            else {
                dp[i][j] = 1 + dp[i + 1][j];

                if (c[i] == c[i + 1])
                    dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);

                for (int k = i + 2; k <= j; ++k)
                    if (c[i] == c[k])
                        dp[i][j] =
                            min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
            }
        }

    cout << dp[0][n - 1] << '\n';
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