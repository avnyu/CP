#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define fi first
#define se second

using namespace std;

namespace DLIT {

const int N = 1 << 21;
const ll M = INT64_MAX;
int cur = 1;
vector<pll> it(N << 2);
vi nl(N << 2, 0), nr(N << 2, 0);

ll get(pll& d, int p) { return d.fi * p + d.se; }
void update(int i, int l, int r, pll v) {
    if (get(it[i], l) < get(v, l) && get(it[i], r) < get(v, r)) {
        it[i] = v;
    } else if (get(it[i], l) >= get(v, l) && get(it[i], r) >= get(v, r))
        return;
    else {
        int m = (l + r) >> 1;
        if (!nl[i]) {
            nl[i] = ++cur;
            nr[i] = ++cur;
        }
        update(nl[i], l, m, v);
        update(nr[i], m + 1, r, v);
    }
}
void add(int b, int e, pll v, int i = 1, int l = 0, int r = N - 1) {
    if (r < b || l > e) return;
    if (b <= l && r <= e) {
        update(i, l, r, v);
        return;
    }
    if (!nl[i]) {
        nl[i] = ++cur;
        nr[i] = ++cur;
    }
    int m = (l + r) >> 1;
    add(b, e, v, nl[i], l, m);
    add(b, e, v, nr[i], m + 1, r);
}
ll query(int p, int i = 1, int l = 0, int r = N - 1) {
    if (p < l || p > r) return -M;
    ll res = get(it[i], p);
    if (l == r) return res;
    int m = (l + r) >> 1;
    if (!nl[i]) {
        nl[i] = ++cur;
        nr[i] = ++cur;
    }
    res = max(res, query(p, nl[i], l, m));
    res = max(res, query(p, nr[i], m + 1, r));
    return res;
}
}  // namespace DLIT