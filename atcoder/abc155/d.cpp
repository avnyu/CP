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

ll cal(vector<ll>& pos, vector<ll>& neg, ll zero, ll m) {
    if (m > 0) {
        ll res = 1LL * pos.size() * neg.size() +
                 zero * (pos.size() + neg.size()) + 1LL * (zero - 1) * zero / 2;
        for (int i = 0; i < pos.size(); ++i) {
            res += lower_bound(pos.begin() + i + 1, pos.end(),
                               (m - 1) / pos[i] + 1) -
                   pos.begin() - i - 1;
        }
        for (int i = 0; i < neg.size(); ++i) {
            res += lower_bound(neg.begin() + i + 1, neg.end(),
                               (m - 1) / neg[i] + 1) -
                   neg.begin() - i - 1;
        }
        return res;
    } else if (m == 0)
        return 1LL * pos.size() * neg.size();
    else {
        ll res = 0;
        for (int i = 0; i < pos.size(); ++i) {
            res += neg.size() -
                   (lower_bound(all(neg), (-m) / pos[i] + 1) - neg.begin());
        }
        return res;
    }
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> pos, neg, a;
    int zero = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.eb(x);
        if (x > 0)
            pos.eb(x);
        else if (x == 0)
            zero++;
        else
            neg.eb(-x);
    }

    sort(all(pos));
    sort(all(neg));
    ll l = -1e18, r = 1e18, resr;
    while (l <= r) {
        ll m = (l + r) >> 1;
        ll cnt = cal(pos, neg, zero, m);
        if (cnt < k) {
            l = m + 1;
            resr = m;
        } else {
            r = m - 1;
        }
    }
    cout << resr << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}