#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll x0, y0, ax, ay, bx, by, sx, sy, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> sx >> sy >> t;

    vector<pair<ll, ll>> p;
    while (x0 + y0 <= (ll)4e16) {
        p.push_back({x0, y0});
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }

    int res = 0, n = p.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            for (int k = i; k < n; ++k) {
                ll dis = abs(sx - p[i].fi) + abs(sy - p[i].se);
                dis += p[k].fi - p[j].fi + p[k].se - p[j].se;
                dis += min(p[k].fi - p[i].fi + p[k].se - p[i].se,
                           p[i].fi - p[j].fi + p[i].se - p[j].se);
                if (dis <= t) res = max(res, k - j + 1);
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