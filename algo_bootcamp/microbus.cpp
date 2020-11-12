#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

void solve(int T) {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    vi a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& j : b) cin >> j;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    const int inf = 1e9;
    vvi dp(n + 1, vi(m + 1, inf));

    dp[0][0] = 0;
    for (int i = 0; i++ < n;) dp[i][0] = i * p;
    for (int j = 0; j++ < m;) dp[0][j] = j * q;

    for (int i = 0; i++ < n;)
        for (int j = 0; j++ < m;) {
            dp[i][j] = dp[i - 1][j - 1] + abs(a[i - 1] - b[j - 1]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + p);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + q);
        }

    print(dp[n][m]);
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