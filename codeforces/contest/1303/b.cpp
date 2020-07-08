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
    ll n, g, b;
    cin >> n >> g >> b;
    ll l = 0, r = 1e18, res = 0;
    while (l <= r) {
        ll m = (l + r) >> 1;
        ll x = m / (g + b) * g + min(g, m % (g + b));
        ll y = m / (g + b) * b + max(0LL, m % (g + b) - g);
        if (x + x >= n && x + y >= n) {
            res = m;
            r = m - 1;
        } else
            l = m + 1;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}