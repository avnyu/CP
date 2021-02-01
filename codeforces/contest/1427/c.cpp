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
    int r, n;
    cin >> r >> n;
    vvi a(n + 1, vi{0, 1, 1});
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 3; ++j) cin >> a[i][j];

    vvi dp(n + 1, vi(2));
    dp[0][0] = dp[0][1] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0 && i - j <= 2 * r; --j)
            if (a[i][0] - a[j][0] >=
                    abs(a[i][1] - a[j][1]) + abs(a[i][2] - a[j][2]) &&
                dp[j][0] > 0) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }

        if (i >= r + r) dp[i][0] = max(dp[i][0], dp[i - r - r][1] + 1);

        dp[i][1] = max(dp[i][0], dp[i - 1][1]);
    }

    cout << dp[n][1] - 1 << '\n';

    // for (int i = 0; i <= n; ++i) cout << dp[i][0] << " " << dp[i][1] << "\n";
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