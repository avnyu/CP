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

using namespace std;

void solve() {
    string s;
    cin >> s;
    int q, n = s.size();
    cin >> q;
    vvi a(26, vi(n + 1));
    for (int i = 0; i < n; ++i) a[s[i] - 'a'][i + 1]++;
    for (auto& i : a) partial_sum(all(i), i.begin());
    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == r)
            cout << "Yes\n";
        else {
            int mx = 0;
            for (int i = 0; i < 26; ++i) mx = max(mx, a[i][r] - a[i][l - 1]);
            cout << ((mx + mx <= r - l + 1) ? "Yes\n" : "No\n");
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}