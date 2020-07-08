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
    vi b(n + n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    set<int> s;
    for (int i = 1; i <= n + n; ++i) s.insert(i);

    vector<ii> a(n);
    for (int i = 0; i < n; ++i) a[i] = {b[i], i};
    sort(rall(a));

    for (int i = 0; i < n; ++i) {
        int v, p;
        tie(v, p) = a[i];
        if (s.find(v) == s.end()) {
            cout << "-1\n";
            return;
        }
        b[p << 1] = v;
        s.erase(v);
    }
    for (int i = 0; i < n; ++i) {
        auto x = s.upper_bound(b[i << 1]);
        if (x == s.end()) {
            cout << "-1\n";
            return;
        }
        b[i << 1 | 1] = *x;
        s.erase(x);
    }
    for (int i = 0; i < n + n; ++i) cout << b[i] << " \n"[i == n + n - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}