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

    int n;
    cin >> n;
    int dp[2][3] = {}, p = 0, q;
    for (int i = 0; i < n; ++i) {
        p = 1 - p, q = 1 - p;
        cin >> dp[q][0] >> dp[q][1] >> dp[q][2];
        dp[q][0] += max(dp[p][1], dp[p][2]);
        dp[q][1] += max(dp[p][0], dp[p][2]);
        dp[q][2] += max(dp[p][0], dp[p][1]);
    }
    cout << max(dp[q][0], max(dp[q][1], dp[q][2])) << '\n';

    return 0;
}