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

struct St {
    int lef, rig, val, laz;
};
vector<St> st(15e6);
int cnt;

void push(int t, int b, int m, int e) {
    int &l = st[t].lef, &r = st[t].rig;
    if (!l) {
        l = cnt++;
        st[l].val = m + 1 - b;
    }
    if (!r) {
        r = cnt++;
        st[r].val = e - m;
    }
    if (!st[t].laz) return;
    if (st[t].laz == 1) {
        st[l].laz = st[r].laz = 1;
        st[l].val = st[r].val = 0;
    } else {
        st[l].laz = st[r].laz = 2;
        st[l].val = m - b + 1;
        st[r].val = e - m;
    }
    st[t].laz = 0;
}
void upd(int t) { st[t].val = st[st[t].lef].val + st[st[t].rig].val; }
void modify(int t, int v, int l, int r, int b, int e) {
    if (b > r || e < l) return;
    if (l <= b && e <= r) {
        st[t].laz = v;
        st[t].val = v == 1 ? 0 : e - b + 1;
        return;
    }
    int m = (b + e) >> 1;
    push(t, b, m, e);
    modify(st[t].lef, v, l, r, b, m);
    modify(st[t].rig, v, l, r, m + 1, e);
    upd(t);
}
int get(int t, int l, int r, int b, int e) {
    if (b > r || e < l) return 0;
    if (l <= b && e <= r) return st[t].val;
    int m = (b + e) >> 1;
    push(t, b, m, e);
    upd(t);
    return get(st[t].lef, l, r, b, m) + get(st[t].rig, l, r, m + 1, e);
}

void solve() {
    int n, q;
    cin >> n >> q;
    cnt = 1;
    for (; q--;) {
        int l, r, k;
        cin >> l >> r >> k;
        modify(0, k, l, r, 1, n);
        cout << get(0, 1, n, 1, n) << '\n';
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