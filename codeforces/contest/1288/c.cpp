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

void solve() {
    int n, m;
    const int M = 1e9 + 7;
    cin >> n >> m;
    vvi asc(m + 1, vi(n)), des(m + 1, vi(n));
    asc[0][0] = des[0][n - 1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j)
            for (int pj = 0; pj <= j; ++pj)
                asc[i][j] = (asc[i][j] + asc[i - 1][pj]) % M;

        for (int j = 0; j < n; ++j)
            for (int pj = j; pj < n; ++pj)
                des[i][j] = (des[i][j] + des[i - 1][pj]) % M;
    }
    ll res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            res = (res + (1LL * asc[m][i] * des[m][j]) % M) % M;

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}