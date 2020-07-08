#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e4 + 7, K = 5e2 + 7;
int n, k, i;
vector<vector<int>> g(N), cnt(N, vector<int>(K, 0));
vector<char> pas(N);
vector<lli> dp(N);

void dfs(int u) {
    pas[u] = 1;

    cnt[u][0] = 1;
    for (auto& v : g[u]) {
        if (pas[v]) continue;

        dfs(v);

        for (i = 1; i < K; ++i) cnt[u][i] += cnt[v][i - 1];

        for (i = 1; i + i < k; ++i)
            dp[u] -= 1LL * cnt[v][i - 1] * cnt[v][k - i - 1];
        if (!(k & 1))
            dp[u] -=
                1LL * cnt[v][(k >> 1) - 1] * (cnt[v][(k >> 1) - 1] - 1) / 2;
    }

    dp[u] += cnt[u][k];
    for (i = 1; i + i < k; ++i) dp[u] += 1LL * cnt[u][i] * cnt[u][k - i];
    if (!(k & 1)) dp[u] += 1LL * cnt[u][k >> 1] * (cnt[u][k >> 1] - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    cin >> n >> k;
    for (i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1);

    partial_sum(dp.begin(), dp.end(), dp.begin());
    cout << dp.back() << '\n';

    // for (int i = 1; i <= n; ++i)
    //     for (int j = 0; j <= k; ++j) cout << cnt[i][j] << " \n"[j == k];
    // for (int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];

    return 0;
}