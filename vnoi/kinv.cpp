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

const int M = 1e9;
const int N = 1e4 + 7;
vvi ft(12, vi(N));

void upd(vi &a, int p, int v) {
    for (; p < N; p += p & -p) a[p] = (a[p] + v) % M;
}
int get(vi &a, int p) {
    int res = 0;
    for (; p; p -= p & -p) res = (res + a[p]) % M;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1, 9e18 + 7);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<ll> b(all(a));
    sort(all(b));

    // for (int i = 0; i < b.size(); ++i) cout << b[i] << " \n"[i == b.size() -
    // 1];

    upd(ft[0], 1, 1);
    for (int i = 1; i <= n; ++i) {
        int p = n + 1 - (lower_bound(all(b), a[i]) - b.begin());
        for (int j = k; j; --j) {
            upd(ft[j], p, get(ft[j - 1], p - 1));
            // cout << "upd ft " << j << " - " << p << " - "
            //      << get(ft[j - 1], p - 1) << '\n';
        }
    }
    cout << get(ft[k], n + 1) << '\n';
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}