#include <bits/stdc++.h>

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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    const int M = 1e9 + 7;
    int n, p, k, x, y;
    string s;
    cin >> n >> p >> k >> s >> x >> y;

    vi dp(n + 1, M);

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (i >= p - 1) dp[i] = min(dp[i], (i - p + 1) * y + x);
            if (i >= k) dp[i] = min(dp[i], dp[i - k] + x);
        } else {
            if (i >= p - 1) dp[i] = min(dp[i], (i - p + 1) * y);
            if (i >= k) dp[i] = min(dp[i], dp[i - k]);
        }
    }

    int res = M;
    for (int i = n - k; i < n; ++i) res = min(res, dp[i]);

    print(res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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