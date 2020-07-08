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

double f(vector<ii>& a, double x, double y) {
    double res = 0;
    for (auto& i : a)
        res = max(res, (i.fi - x) * (i.fi - x) + (i.se - y) * (i.se - y));
    return res;
}

int check(vector<ii>& a, vector<dd>& go, double L, double x, double y) {
    double org = f(a, x, y);
    int res = -1;
    for (int i = 0; i < go.size(); ++i) {
        double tmp = f(a, x + L * go[i].fi, y + L * go[i].se);
        if (tmp < org) {
            org = tmp;
            res = i;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].fi >> a[i].se;
    vector<pair<double, double>> go(360);
    const double PI = acos(-1);
    for (int i = 0; i < go.size(); ++i) {
        go[i].fi = sin(PI * i * 2 / go.size());
        go[i].se = cos(PI * i * 2 / go.size());
    }
    double L = 1000, cnt = 100;
    double x = 0, y = 0;
    while (cnt--) {
        int cnt_check = 10, t = check(a, go, L, x, y);
        while (t == -1 && cnt_check--) {
            L /= 2;
            t = check(a, go, L, x, y);
        }
        x += go[t].fi * L;
        y += go[t].se * L;
    }
    cout << fixed << setprecision(15) << sqrt(f(a, x, y)) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}