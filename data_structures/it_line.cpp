#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define fi first
#define se second

using namespace std;

namespace it_line {

const int B = 17;
const int N = 1 << B;
const ll M = INT64_MAX;
vector<pll> it(N << 1);
vi low(N << 1), high(N << 1);

void init() {
    int cur, h, m;
    m = 32 - __builtin_clz(N);
    for (int i = 1; i < N << 1; ++i) {
        if (!(i & (i - 1))) cur = 0;
        h = m - (32 - __builtin_clz(i));
        low[i] = cur;
        high[i] = cur + (1 << h) - 1;
        cur += 1 << h;
    }
}
ll get(pll& d, int p) { return d.fi * p + d.se; }
void update(int i, pair<ll, ll> v) {
    if (get(it[i], low[i]) > get(v, low[i]) &&
        get(it[i], high[i]) > get(v, high[i]))
        it[i] = v;
    else if (get(it[i], low[i]) <= get(v, low[i]) &&
             get(it[i], high[i]) <= get(v, high[i]))
        return;
    else {
        update(i << 1, v);
        update(i << 1 | 1, v);
    }
}
ll query(int p, int i = 1) {
    if (p < low[i] || p > high[i]) return M;
    ll res = get(it[i], p);
    if (low[i] == high[i]) return res;
    res = min(res, query(p, i << 1));
    res = min(res, query(p, i << 1 | 1));
    return res;
}
void add(int b, int e, pll v, int i = 1) {
    if (high[i] < b || low[i] > e) return;
    if (b <= low[i] && high[i] <= e) {
        update(i, v);
        return;
    }
    add(b, e, v, i << 1);
    add(b, e, v, i << 1 | 1);
}
}  // namespace it_line