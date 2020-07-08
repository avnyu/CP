#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define dd pair<double, double>
#define fi first
#define se second
#define vd vector<double>
#define vi vector<int>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (auto& i : a)
        for (auto& j : i) cin >> j;

    const int M = 1e9 + 7;
    ll val = -1, resx = -1, resy = -1;
    vector<ii> best_index(1 << m, {-1, -1});
    for (int i = 0; i < n; ++i) {
        for (int msk = 1; msk < (1 << m); ++msk) {
            int mini = M;
            for (int j = 0; j < m; ++j)
                if (msk & (1 << j)) mini = min(mini, a[i][j]);

            if (mini > best_index[msk].fi) best_index[msk] = {mini, i};
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<ii> x(m);
        for (int j = 0; j < m; ++j) x[j] = {a[i][j], j};
        sort(x.begin(), x.end());

        if (x[0].fi > val) {
            val = x[0].fi;
            resx = resy = i + 1;
        }

        int msk = 1 << x[0].se;
        for (int j = 1; j < m; ++j) {
            ii best = best_index[msk];
            int tmp = min(best.fi, x[j].fi);
            if (tmp > val) {
                val = tmp;
                resx = i + 1;
                resy = best_index[msk].se + 1;
            }

            msk += (1 << x[j].se);
        }
    }

    cout << resx << ' ' << resy << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}