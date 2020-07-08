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

using namespace std;

int test(vi a, int lef, int rig, int rem) {
    int res = 1e9;
    for (int i = 0; i < rem; ++i)
        res = min(res, max(a[lef + i], a[rig - (rem - 1 - i)]));
    // cout << lef << ' ' << rig << ' ' << rem << ' ' << res << '\n';
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (auto& i : a) cin >> i;

    k = min(k, m - 1);
    int res = 0;
    for (int i = 0; i <= k; ++i)
        res = max(res, test(a, i, n - 1 - (k - i), m - k));
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