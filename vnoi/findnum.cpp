#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))
#define repx(i, a, b, x) for (auto i = a; i < b; i += x)

using namespace std;

void solve() {
    int n;
    cin >> n;
    int N = 1e3 + 1, M = 18;
    vi maxPrime(N, 0), primes;
    iota(all(maxPrime), 0);
    rep(i, 2, N) if (i == maxPrime[i]) {
        repx(j, i + i, N, i) maxPrime[j] = i;
        primes.eb(i);
    }
    vector<vector<ll>> dp(M, vector<ll>(N, 2e18));
    double l2m = log2(4e18);
    rep(i, 0, M) dp[i][1] = 1;
    rep(i, 0, M - 1) rep(j, 1, N) repx(k, j + j, N, j) {
        ll nxt = dp[i][j] * pow(1LL * primes[i], 1LL * (k / j - 1));
        if (nxt > 0) dp[i + 1][k] = min(dp[i + 1][k], nxt);
    }
    ll res = 2e18;
    for (int i = 0; i < M; ++i) res = min(res, dp[i][n]);
    cout << res << '\n';
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}