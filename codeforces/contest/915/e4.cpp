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

unordered_map<int, ii> st;
int B, E;

inline void push(int i, int b, int m, int e) {
    if (!st[i].se) return;
    if (st[i].se == 1) {
        st[i << 1].fi = st[i << 1 | 1].fi = 0;
        st[i << 1].se = st[i << 1 | 1].se = 1;
    } else {
        st[i << 1].fi = m - b;
        st[i << 1 | 1].fi = e - m;
        st[i << 1].se = st[i << 1 | 1].se = 2;
    }
    st[i].se = 0;
}
inline void upd(int i) { st[i].fi = st[i << 1].fi + st[i << 1 | 1].fi; }

void modify(int l, int r, int v, int i = 1, int b = B, int e = E) {
    if (l >= e || r <= b) return;
    if (l <= b && e <= r) {
        st[i].se = v;
        st[i].fi = v == 2 ? e - b : 0;
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
    if (l <= b && e <= r) { return st[i].fi; }
    int m = b + e >> 1;
    push(i, b, m, e);
    upd(i);
    return get(l, r, i << 1, b, m) + get(l, r, i << 1 | 1, m, e);
}

void solve() {
    int n, q;
    cin >> n >> q;
    st.reserve(15e6);
    B = 0, E = n;
    modify(0, n, 2);

    for (; q--;) {
        int l, r, k;
        cin >> l >> r >> k;
        modify(l - 1, r, k);
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