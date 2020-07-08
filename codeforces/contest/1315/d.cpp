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
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].fi;
    for (int i = 0; i < n; ++i) cin >> a[i].se;

    sort(all(a));
    set<int> in;
    int cur = 0;
    for (auto &i : a) {
        if (i.fi > cur)
            cur = i.fi;
        else
            cur++;
        in.insert(cur);
    }

    sort(all(a), [](ii &x, ii &y) { return x.se > y.se; });
    ll res = 0;
    for (auto &i : a) {
        int u = *in.lower_bound(i.fi);
        res += 1LL * (u - i.fi) * i.se;
        in.erase(u);
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