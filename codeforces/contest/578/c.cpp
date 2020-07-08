#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define dd pair<double, double>
#define fi first
#define se second
#define vd vector<double>
#define vi vector<int>
#define vvd vector<vector<double>>
#define vvi vector<vector<int>>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

double f(vd &a, double x) {
    double sumneg = 0, sumpos = 0;
    double curneg = 0, curpos = 0;
    for (auto &i : a) {
        curneg += i - x;
        curpos += i - x;
        if (curneg > 0) curneg = 0;
        if (curpos < 0) curpos = 0;
        sumneg = min(sumneg, curneg);
        sumpos = max(sumpos, curpos);
    }
    return max(-sumneg, sumpos);
}

void solve() {
    int n;
    cin >> n;
    vd a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    double l = -20000, r = 20000;
    int cnt = 100;
    while (cnt--) {
        double m1 = (l + l + r) / 3;
        double m2 = (l + r + r) / 3;
        if (f(a, m1) > f(a, m2))
            l = m1;
        else
            r = m2;
    }

    cout << fixed << setprecision(18) << f(a, l) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}