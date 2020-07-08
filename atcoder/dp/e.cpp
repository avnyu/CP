#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    ll n, w, wi, vi, M = 1e9 + 7;
    cin >> n >> w;
    ll dp[100001] = {};
    memset(dp, M, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> wi >> vi;
        for (int j = 100000; j >= vi; --j) dp[j] = min(dp[j], dp[j - vi] + wi);
        // for (int j = 0; j <= w; ++j) cout << dp[j] << " \n"[j == w];
    }
    for (int i = 100001; i--;)
        if (dp[i] <= w) {
            cout << i << '\n';
            return 0;
        }
    cout << 0 << '\n';

    return 0;
}