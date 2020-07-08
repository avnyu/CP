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

void solve() {
    int n, m;
    ll res = 0;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            int lef = j, rig = m - j;
            int up = i, down = n - i;
            res += (up / 2 + down / 2 + 1) * (lef / 2 + rig / 2 + 1) - 1;
            // printf("up %d down %d lef %d rig %d\n", up, down, lef, rig);
        }
    cout << res / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}