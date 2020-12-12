#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 2e18 + 7;

ll lower(ll u, ll n) {
    ll cur = 2, res = 0;
    while (n) {
        res += 1 < u;
        n--;

        ll k = min(n, (cur - 1) << 1);

        ll lef_low = min(u, cur - (k + 1) / 2 + 1);
        ll lef_high = min(u, cur + 1);
        ll rig_low = min(u, cur * 2);
        ll rig_high = min(u, cur * 2 + k / 2);

        res += lef_high - lef_low;
        res += rig_high - rig_low;

        n -= k;
        cur = cur * 3 - 1;
    }
    return res;
}
void solve() {
    ll n, m;
    cin >> n >> m;

    ll l = 0, add = 1LL << 60;
    while (add) {
        if (lower(l + add, n) < m) l += add;
        add >>= 1;
    }
    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (; t--;) solve();

    return 0;
}
