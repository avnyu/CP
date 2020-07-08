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
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;

    vvi g(32);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 31; ++j)
            if (a[i] & (1 << j)) g[j].push_back(i);
    for (int i = 30; i >= 0; --i)
        if (g[i].size() == 1) {
            swap(a[0], a[g[i][0]]);
            break;
        }
    for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}