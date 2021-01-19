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

const int N = 87;
const int M = 1e5 + 7;
int n, m;
vii p(N);
vi dp(M);

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> p[i].fi >> p[i].se;
    // sort(p.begin(), p.end());

    fill(dp.begin() + 1, dp.end(), M);

    for (int j = 1; j <= m; ++j) {
        for (int i = 0; i < n; ++i) if (p[i].fi + p[i].se >= j) {
            int cst = max(0, p[i].fi - p[i].se - j);
            int nxt = min(m, p[i].fi + p[i].se + cst);
            dp[nxt] = min(dp[nxt], dp[j - 1] + cst);
        }
        dp[j] = min(dp[j], dp[j - 1] + 1);
    }

    cout << dp[m] << '\n';
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