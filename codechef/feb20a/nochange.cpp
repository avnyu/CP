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
    int n, p;
    cin >> n >> p;
    vi a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    copy(all(a), b.begin());
    sort(rall(b));
    for (int i = 0; i < n; ++i) {
        int p = n - 1 - (lower_bound(rall(b), a[i]) - b.rbegin());
        d[p] = i;
    }
    for (int i = 0; i < n; ++i) {
        c[d[i]] = (p - 1) / b[i];
        p -= ((p - 1) / b[i]) * b[i];
        // cout << b[i] << ' ' << d[i] << '\n';
        if (p < b[i]) {
            c[d[i]]++;
            p -= b[i];
            break;
        }
    }
    if (p < 0) {
        cout << "YES ";
        for (int i = 0; i < n; ++i) cout << c[i] << " \n"[i == n - 1];
    } else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}