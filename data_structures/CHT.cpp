#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second

using namespace std;

namespace CHT {  // min CHT
const ll M = INT64_MAX;
vector<pll> st;
vector<double> pt;
double get(pll x, pll y) { return double(x.se - y.se) / (y.fi - x.fi); }
void add_lines(vector<pll> lines) {
    int n = lines.size();

    sort(lines.rbegin(), lines.rend());

    for (int i = 0; i < n; ++i) {
        if (st.size() && st.back().fi == lines[i].fi) st.pop_back();

        while (1) {
            if (int(st.size()) < 2) {
                st.push_back(lines[i]);
                break;
            }

            int sts = st.size();
            pll &x = st[sts - 2], &y = st[sts - 1], &z = lines[i];
            double c1 = get(x, y), c2 = get(y, z);

            if (c1 < c2) {
                st.push_back(z);
                break;
            } else
                st.pop_back();
        }
    }

    pt.push_back(-M);
    for (int i = 1; i < int(st.size()); ++i)
        pt.push_back(get(st[i - 1], st[i]));
    pt.push_back(M);
}
ll get(ll x) {
    int p = int(pt.size()) - 1, add = 1 << 17;
    while (add) {
        if (p - add >= 0 && x < pt[p - add]) p -= add;

        add >>= 1;
    }
    p--;

    ll ans = x * st[p].fi + st[p].se;
    return ans;
}
}  // namespace CHT