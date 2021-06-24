#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vi vector<int>
#define fi first
#define se second

using namespace std;

namespace LIT {

const int N = 1 << 17;
const ll M = INT64_MAX;
vector<pll> it(N << 1);
vi lef(N << 1), rig(N << 1);

// change for max or min
template <typename T>
bool better(T a, T b) {
    return a > b;
}
const ll bad = -M;
//

void asg(int i = 1, int l = 0, int r = N - 1) {
    lef[i] = l;
    rig[i] = r;
    if (l == r) return;
    int m = (l + r) >> 1;
    asg(i << 1, l, m);
    asg(i << 1 | 1, m + 1, r);
}
ll get(pll& d, int p) { return d.fi * p + d.se; }
void update(int i, pair<ll, ll> v) {
    bool blef = better(get(v, lef[i]), get(it[i], lef[i]));
    bool brig = better(get(v, rig[i]), get(it[i], rig[i]));

    if (blef && brig)
        it[i] = v;
    else if (!blef && !brig)
        return;
    else {
        update(i << 1, v);
        update(i << 1 | 1, v);
    }
}
ll query(int p, int i = 1) {
    if (p < lef[i] || p > rig[i]) return bad;
    ll res = get(it[i], p);
    if (lef[i] == rig[i]) return res;
    ll qlef = query(p, i << 1);
    ll qrig = query(p, i << 1 | 1);
    if (better(qlef, res)) res = qlef;
    if (better(qrig, res)) res = qrig;
    return res;
}
void add(int b, int e, pll v, int i = 1) {
    if (rig[i] < b || lef[i] > e) return;
    if (b <= lef[i] && rig[i] <= e) {
        update(i, v);
        return;
    }
    add(b, e, v, i << 1);
    add(b, e, v, i << 1 | 1);
}
void reset() {
    for (auto& p : it) p = pll{0, 0};
}
}  // namespace LIT