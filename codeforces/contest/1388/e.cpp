#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pair<ll, ll>>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

namespace CHT {
const ll M = INT64_MAX;
vector<pll> cht;
vector<double> pt;
double intersect(pll& x, pll& y) { return double(x.se - y.se) / (y.fi - x.fi); }
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
double get(double x) {
    auto p = upper_bound(pt.begin(), pt.end(), x) - pt.begin() - 1;
    return x * cht[p].fi + cht[p].se;
}
void reset() {
    cht.clear();
    pt.clear();
}
}  // namespace CHT

dd get(vi& u, vi& v) {
    return {double(u[0] - v[1]) / (v[2] - u[2]),
            double(u[1] - v[0]) / (v[2] - u[2])};
}
void solve(int T) {
    // cout << "Case #" << T << ": \n";

    int n;
    cin >> n;
    vvi a(n, vi(3));
    for (auto& i : a)
        for (auto& j : i) cin >> j;

    vii pts;
    for (int i = 0; i < n; ++i) {
        pts.push_back(ii{a[i][2], a[i][0]});
        pts.push_back(ii{a[i][2], a[i][1]});
    }
    sort(pts.begin(), pts.end());

    vdd seg;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][2] < a[j][2]) seg.push_back(get(a[i], a[j]));
    sort(seg.begin(), seg.end());

    if (seg.empty()) {
        int mn = 1e9, mx = -1e9;
        for (auto& p : pts) {
            mn = min(mn, p.se);
            mx = max(mx, p.se);
        }
        print(mx - mn);
        return;
    }

    vdd final;
    for (auto& s : seg) {
        if (final.empty())
            final.push_back(s);
        else if (final.back().se <= s.fi)
            final.push_back(s);
        else if (s.se > final.back().se)
            final.back().se = s.se;
    }

    vd vt;
    for (auto& s : final) {
        vt.push_back(s.fi);
        vt.push_back(s.se);
    }

    int m = vt.size();
    const double M = 1e18;
    vd max_pts(m), min_pts(m);

    CHT::reset();
    for (auto& p : pts) CHT::add(pll{p.fi, p.se});
    for (int i = 0; i < m; ++i) max_pts[i] = CHT::get(vt[i]);

    CHT::reset();
    sort(pts.rbegin(), pts.rend());
    for (auto& p : pts) CHT::add(pll{p.fi, p.se});
    for (int i = 0; i < m; ++i) min_pts[i] = CHT::get(vt[i]);

    double res = M;
    for (int i = 0; i < m; ++i) res = min(res, abs(max_pts[i] - min_pts[i]));

    cout << fixed << setprecision(9);
    print(res);

    // print("VT");
    // for (int i = 0; i < m; ++i) print(vt[i], min_pts[i], max_pts[i]);

    // print("Pts");
    // for (auto& p : pts) print(p.fi, p.se);

    // print("Seg");
    // for (auto& s : seg) print(s.fi, s.se);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}