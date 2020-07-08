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

const int M = 1e9 + 7;

void update(int &l, int &r, int t0, int t1, int lb, int rb) {
    l -= t1 - t0;
    r += t1 - t0;
    l = max(l, lb);
    r = min(r, rb);
    if (l > r) l = r = M;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<iii> a(n);
    for (int i = 0; i < n; ++i) {
        int t, l, h;
        cin >> t >> l >> h;
        a[i] = {t, l, h};
    }
    sort(all(a));
    int l = m, r = m, t = 0;
    for (auto &i : a) {
        int ti, li, hi;
        tie(ti, li, hi) = i;
        update(l, r, t, ti, li, hi);
        t = ti;
        if (l == M) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}