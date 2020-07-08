#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
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

double f(vector<ii>& a, double x, double y) {
    double res = 0;
    for (auto& i : a)
        res = max(res, (i.fi - x) * (i.fi - x) + (i.se - y) * (i.se - y));
    return res;
}

double ts(vector<ii>& a, double x) {
    double lef = -M, rig = M;
    int cnt = 100;
    while (cnt--) {
        double y1 = (lef + lef + rig) / 3;
        double y2 = (lef + rig + rig) / 3;
        if (f(a, x, y1) > f(a, x, y2))
            lef = y1;
        else
            rig = y2;
    }
    return sqrt(f(a, x, lef));
}

double cal(vector<ii>& a) {
    double lef = -M, rig = M;
    int cnt = 100;
    while (cnt--) {
        double x1 = (lef + lef + rig) / 3;
        double x2 = (lef + rig + rig) / 3;
        if (ts(a, x1) > ts(a, x2))
            lef = x1;
        else
            rig = x2;
    }
    return ts(a, lef);
}

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].fi >> a[i].se;

    cout << fixed << setprecision(15) << cal(a) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}