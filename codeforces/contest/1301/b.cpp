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
    int n;
    cin >> n;
    vi a(n);
    int m = 0, k = 0, mn = 1e9 + 7, mx = -1;
    for (auto& i : a) cin >> i;
    for (int i = 1; i < n; ++i) {
        if (a[i] != -1 && a[i - 1] != -1) m = max(m, abs(a[i] - a[i - 1]));
        if (a[i] == -1 && a[i - 1] != -1) {
            mn = min(mn, a[i - 1]);
            mx = max(mx, a[i - 1]);
        }
        if (a[i] != -1 && a[i - 1] == -1) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }
    k = (mx + mn) / 2;
    m = max(m, max(mx - k, k - mn));
    cout << m << ' ' << k << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}