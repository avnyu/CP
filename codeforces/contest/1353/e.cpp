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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi ps(n + 1);
    for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + s[i] - '0';

    int res = n;
    vvi dp(n + 1, vi(2));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = ps[i + 1];
        dp[i][1] = ps[i] + (s[i] == '0');
        if (i - k >= 0)
            dp[i][1] =
                min(dp[i][1], dp[i - k][1] + ps[i] - ps[i - k + 1] + (s[i] == '0'));

        // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << " " << ps[n] - ps[i + 1] << '\n';

        res = min(res, dp[i][0] + ps[n] - ps[i + 1]);
        res = min(res, dp[i][1] + ps[n] - ps[i + 1]);
    }

    cout << res << '\n';
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