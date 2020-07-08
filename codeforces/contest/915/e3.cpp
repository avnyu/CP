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
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

const int N = 1 << 20;
vi laz(N << 1), val(N << 1), a(N, 1);
int B, E;

inline int cal(int b, int e) { return a[e] - a[b]; }
inline void push(int i, int b, int m, int e) {
    if (!laz[i]) return;
    if (laz[i] == 1) {
        val[i << 1] = val[i << 1 | 1] = 0;
        laz[i << 1] = laz[i << 1 | 1] = 1;
    } else {
        val[i << 1] = cal(b, m);
        val[i << 1 | 1] = cal(m, e);
        laz[i << 1] = laz[i << 1 | 1] = 2;
    }
    laz[i] = 0;
}
inline void upd(int i) { val[i] = val[i << 1] + val[i << 1 | 1]; }

void modify(int l, int r, int v, int i = 1, int b = B, int e = E) {
    if (l >= e || r <= b) return;
    if (l <= b && e <= r) {
        laz[i] = v;
        val[i] = v == 2 ? cal(b, e) : 0;
        return;
    }
    int m = b + e >> 1;
    push(i, b, m, e);
    modify(l, r, v, i << 1, b, m);
    modify(l, r, v, i << 1 | 1, m, e);
    upd(i);
}
int get(int l, int r, int i = 1, int b = B, int e = E) {
    if (l >= e || r <= b) return 0;
    if (l <= b && e <= r) {
        return val[i];
    }
    int m = b + e >> 1;
    push(i, b, m, e);
    upd(i);
    return get(l, r, i << 1, b, m) + get(l, r, i << 1 | 1, m, e);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vvi query(q, vi(3));
    for (auto& i : query)
        for (auto& j : i) cin >> j;

    a.eb(0);
    a.eb(n);
    for (auto& i : query) {
        a.eb(i[0] - 1);
        a.eb(i[1]);
    }
    sort(all(a));
    uni(a);
    // for (auto& i : a) cout << i << " \n"[i == a.back()];
    B = 0, E = a.size() - 1;
    modify(B, E, 2);

    for (auto& i : query) {
        int &l = i[0], &r = i[1], &k = i[2];
        l = lower_bound(all(a), l - 1) - a.begin();
        r = lower_bound(all(a), r) - a.begin();
        modify(l, r, k);
        cout << get(B, E) << '\n';
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