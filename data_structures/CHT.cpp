#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second

using namespace std;

namespace CHT {
const ll M = INT64_MAX;
vector<pll> cht;
vector<double> pt;
double intersect(pll &x, pll &y) { return double(x.se - y.se) / (y.fi - x.fi); }
void add(pll line) {
    if (cht.size() && cht.back().fi == line.fi) {
        pt.pop_back();
        cht.pop_back();
    }
    while (cht.size() && intersect(cht.back(), line) <= pt.back()) {
        pt.pop_back();
        cht.pop_back();
    }
    pt.push_back(cht.empty() ? -M : intersect(cht.back(), line));
    cht.push_back(line);
}
void add_lines(vector<pll> lines) {
    int n = lines.size();
    sort(lines.begin(), lines.end());
    for (int i = 0; i < n; ++i) add(lines[i]);
}
ll get(ll x) {
    auto p = upper_bound(pt.begin(), pt.end(), double(x)) - pt.begin() - 1;
    return cht[p].fi * x + cht[p].se;
}
}  // namespace CHT