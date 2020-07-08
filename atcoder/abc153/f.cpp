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

void solve() {
    const ll M = 1e9;
    int n, d, x;
    cin >> n >> d >> x;
    vector<pair<ll, ll>> a(n);
    vector<ll> c(n);
    for (auto& i : a) cin >> i.fi >> i.se;
    sort(all(a));
    int i = 0, j = 0;
    ll res = 0;
    while (i < n) {
        if (i) c[i] += c[i - 1];

        int y = a[i].fi + d + d;
        while (j < n && a[j].fi <= y) j++;

        if (a[i].se - c[i] > 0) {
            int z = (a[i].se - c[i] - 1) / x + 1;
            res += z;
            c[i] += z * x;
            if (j < n) c[j] -= z * x;
        }

        i++;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}