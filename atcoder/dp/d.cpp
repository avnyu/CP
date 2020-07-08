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

    ll n, w, wi, vi;
    cin >> n >> w;
    ll dp[w + 1] = {};
    for (int i = 0; i < n; ++i) {
        cin >> wi >> vi;
        for (int j = w; j >= wi; --j) dp[j] = max(dp[j], dp[j - wi] + vi);
        // for (int j = 0; j <= w; ++j) cout << dp[j] << " \n"[j == w];
    }
    cout << dp[w] << '\n';

    return 0;
}