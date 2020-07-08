#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

void solve() {
    int n, l, r, k, i, m, j;
    cin >> n;
    vvi dp(n, vi(n, -1));
    for (i = 0; i < n; ++i) cin >> dp[i][i];
    for (k = 1; k < n; ++k)
        for (l = 0; l + k < n; ++l) {
            r = l + k;
            for (m = l; m < r; ++m) {
                if (dp[l][m] == dp[m + 1][r] && dp[l][m] != -1)
                    dp[l][r] = dp[l][m] + 1;
            }
        }
    vi res(n, 1e9);
    res[0] = 1;

    for (i = 1; i < n; ++i)
        for (j = 0; j < i; ++j) {
            if (dp[0][i] != -1) res[i] = 1;
            if (dp[j + 1][i] != -1) res[i] = min(res[i], res[j] + 1);
        }

    cout << res[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}