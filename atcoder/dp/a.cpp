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

    int n, M = 1e9 + 7;
    cin >> n;

    vector<int> h(n), dp(n);
    for (auto& i : h) cin >> i;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        if (i > 1) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp.back() << '\n';

    return 0;
}