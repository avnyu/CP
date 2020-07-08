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

using namespace std;

void solve() {
    string n;
    int k;
    cin >> n >> k;
    vector<vector<vector<ll>>> dp(n.size() + 1,
                                  vector<vector<ll>>(k + 1, vector<ll>(2)));
    dp[0][0][true] = 1;
    for (int i = 0; i < n.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            for (auto low : {false, true}) {
                for (int x = (k == 0); x <= (low ? n[i] - '0' : 9); ++x)
                    dp[i + 1][j + (x > 0)][low && x == n[i] - '0'] +=
                        dp[i][j][low];
            }
        }
        dp[i + 1][k][false] += dp[i][k][false];
        dp[i + 1][k][true] += dp[i][k][true];
    }
    cout << dp[n.size()][k][false] + dp[n.size()][k][true] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}