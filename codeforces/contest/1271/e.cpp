#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll req(ll x, ll k) {
    if (!(x & 1)) {
        x >>= 1;
        k++;
    }
    ll M = 2e18;
    char add = false;
    auto chk_bit = [](ll x, ll i) {
        return ((1LL << i) & x) > 0;
    };
    for (ll i = 60; i >= 0; --i) {
        if (!add)
            add = chk_bit(k, i);
        else {
            x = (x << 1) + chk_bit(k, i);
            if (x > M) return M;
        }
    }
    return x;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll mx = 0;
    ll l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (req(m + m, k) > n) {
            r = m - 1;
        } else {
            mx = max(mx, m + m);
            l = m + 1;
        }
    }
    l = 0, r = 1e18;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (req(m + m + 1, k) > n) {
            r = m - 1;
        } else {
            mx = max(mx, m + m + 1);
            l = m + 1;
        }
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}