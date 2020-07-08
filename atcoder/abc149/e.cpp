#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll pair_count(vector<ll>& a, ll v) {
    ll n = a.size(), res = 0;
    for (int i = 0; i < n; ++i) {
        ll cnt = lower_bound(a.begin(), a.end(), v - a[i]) - a.begin();
        res += n - cnt;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    ll lef = 0, rig = 2e9, val = 0, cnt = 0;

    while (lef <= rig) {
        ll mid = (lef + rig) >> 1;
        // cout << lef << ' ' << rig << ' ' << mid << '\n';
        ll cnt_mid = pair_count(a, mid);
        if (cnt_mid >= m) {
            lef = mid + 1;
            val = mid;
            cnt = cnt_mid;
        } else
            rig = mid - 1;
    }

    vector<ll> psum(n + 1);
    partial_sum(a.rbegin(), a.rend(), psum.rbegin() + 1);

    ll res = 1LL * val * (m - cnt);
    for (int i = 0; i < n; ++i) {
        ll pos = lower_bound(a.begin(), a.end(), val - a[i]) - a.begin();
        res += 1LL * (n - pos) * a[i] + psum[pos];
        // cout << i << ' ' << a[i] << ' ' << pos << ' ' << n - pos << ' ' << psum[pos] << ' ' << (n - pos) * a[i] + psum[pos] << '\n';
    }

    cout << res << '\n';
    // cout << val << ' ' << cnt << '\n';
    // for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
    // for (int i = 0; i <= n; ++i) cout << psum[i] << " \n"[i == n];
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}