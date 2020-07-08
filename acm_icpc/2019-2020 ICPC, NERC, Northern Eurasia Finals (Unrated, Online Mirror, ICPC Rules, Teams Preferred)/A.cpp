#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    multiset<ll> b;
    vector<pair<ll, ll>> a(n << 1);

    for (int i = 0; i < n; ++i) {
        ll l, r, t;
        cin >> l >> r >> t;
        l <<= 1;
        r <<= 1;
        t <<= 1;
        r = r - t + 1;
        a[i << 1] = {l, t};
        a[i << 1 | 1] = {r, -t};
    }

    sort(a.begin(), a.end());

    ll z = 0, cnt = 0;
    for (int i = 0; i < (n << 1); ++i) {
        if (a[i].se > 0)
            b.insert(a[i].se);
        else
            b.erase(b.lower_bound(-a[i].se));

        if (!b.empty()) {
            ll l = a[i].fi, r = a[i + 1].fi;
            if (l + (*b.begin()) < z) z = l + (*b.begin());
            z = max(z, l);

            if (z <= r) {
                ll w = (r - z) / (*b.begin());
                cnt += w;
                z += w * (*b.begin());
            }

            while (z <= r) {
                z += (*b.begin());
                cnt++;
            }
        }
    }

	cout << cnt << '\n';

    return 0;
}