#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define dd pair<double, double>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
vi a, b;

ll cal(int v) {
    vi index;
    for (ll i = v; i <= n; i *= v) index.push_back(i);

    int m = index.size();

    ll res = 0;
    for (int msk = 0; msk < (1 << m); ++msk) {
        ll val = 0;
        for (int i = 0; i < m; ++i)
            if (msk & (1 << i)) val += a[index[i]];

        for (int i = 0; i < m; ++i) {
            if (!(msk & (1 << i))) continue;
            int expi = i + 1;
            int expj = expi + expi;
            while (expj <= m) {
                if (msk & (1 << (expj - 1))) val -= b[index[expj - 1]];
                expj += expi;
            }
        }

        res = max(res, val);
    }

    for (auto& i : index) a[i] = 0;

    return res;
}

void solve() {
    cin >> n;
    a.assign(n + 1, 0);
    b.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    ll res = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0) continue;
        res += cal(i);
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