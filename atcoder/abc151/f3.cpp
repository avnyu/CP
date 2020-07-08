#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define dd pair<double, double>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1e3;
double e = 1e-8;

double f(vector<ii>& a, double x, double y) {
    double res = 0;
    for (auto& i : a)
        res = max(res, sqrt((i.fi - x) * (i.fi - x) + (i.se - y) * (i.se - y)));
    return res;
}

double dx(vector<ii>& a, double x, double y) {
    return (f(a, x + e, y) - f(a, x - e, y)) / e;
}

double dy(vector<ii>& a, double x, double y) {
    return (f(a, x, y + e) - f(a, x, y - e)) / e;
}

bool test(vector<ii>& a, double L, double x, double y) {
    return f(a, x, y) > f(a, x - dx(a, x, y) * L, y - dy(a, x, y) * L);
}

double cal_L(vector<ii>& a, double x, double y, double tdx, double tdy) {
    double lef = -M, rig = M;
    int cnt = 100;
    while (cnt--) {
        double l1 = (lef + lef + rig) / 3;
        double l2 = (lef + rig + rig) / 3;
        if (f(a, x - tdx * l1, y - tdy * l1) > f(a, x - tdx * l2, y - tdy * l2))
            lef = l1;
        else
            rig = l2;
    }
    return lef;
}

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].fi >> a[i].se;

    int cnt = 100;
    double L = 100, x = 0, y = 0;
    while (cnt--) {
        L = L * 0.999;

        double tdx = dx(a, x, y), tdy = dy(a, x, y);
        L = cal_L(a, x, y, tdx, tdy);

        x -= tdx * L;
        y -= tdy * L;
    }
    cout << fixed << setprecision(15) << f(a, x, y) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}