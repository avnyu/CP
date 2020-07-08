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
    int n, m;
    cin >> n, m;
    vector<ii> a(n);
    set<ii> range;
    vi state(n + 1), upd(n + 1), pos(n + n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
        pos.eb(a[i].fi);
    }

    sort(all(pos));
    uni(pos);

    for (int i = 0; i < n; ++i)
        state[lower_bound(all(pos), a[i].fi) - pos.begin()] = a[i].se;

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l = lower_bound(all(pos), l) - pos.begin();
        r = upper_bound(all(pos), r) - pos.begin();
        range.insert({l, r});
    }

    for (int i = 0; i < pos.size(); ++i) {
        
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}