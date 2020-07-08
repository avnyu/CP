#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, s, k;
    cin >> n >> s >> k;
    int f[3000] = {}, res = 1e9;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        if (abs(x - s) < 1200) f[1500 + x - s] = 1;
    }
    int l = max(0, 1500 - s + 1);
    int r = min(3000, 1500 + n - s + 1);
    for (int i = l; i < r; ++i)
        if (f[i] == 0) res = min(res, abs(1500 - i));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}