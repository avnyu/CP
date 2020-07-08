#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 2e5 + 7;
int n;
vector<vector<int>> g(N);
vector<lli> cnt(N), from(N), dp(N);
vector<char> pas(N);

int dfs(int u) {
    pas[u] = 1;
    cnt[u] = 1;

    for (auto& v : g[u]) {
        if (pas[v]) continue;
        cnt[u] += dfs(v);
        from[u] += from[v];
    }

    from[u] += cnt[u];

    return cnt[u];
}

void from_leaf(int u, lli par = 0) {
    pas[u] = 1;
    dp[u] = from[u] + n - cnt[u] + par;

    for (auto& v : g[u])
        if (!pas[v]) from_leaf(v, dp[u] - cnt[v] - from[v]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    pas.assign(N, 0);
    dfs(1);

    pas.assign(N, 0);
    from_leaf(1, 0);

    // for (int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];
    sort(dp.rbegin(), dp.rend());
    cout << dp[0] << '\n';

    return 0;
}