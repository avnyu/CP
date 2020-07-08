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
    string s;
    cin >> s;
    vvi g(128);
    for (int i = 0; i < s.size(); ++i) g[s[i]].push_back(i);

    ll res = 0;
    for (auto& i : g) res = max(res, (ll)(i.size()));

    vector<vector<ll>> cnt(128, vector<ll>(128));
    for (int i = 97; i < 123; ++i)
        for (auto& x : g[i])
            for (int j = 97; j < 123; ++j)
                cnt[i][j] +=
                    g[j].size() - (upper_bound(all(g[j]), x) - g[j].begin());

    for (auto& i : cnt)
        for (auto& j : i) res = max(res, j);
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