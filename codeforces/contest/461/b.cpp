#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1e5 + 7, M = 1e9 + 7;
int n;
vector<int> color(N);
vector<vector<int>> graph(N);
vector<vector<lli>> dp(N, vector<lli>(2));

void dfs(int u = 0) {
    for (auto& v : graph[u]) dfs(v);

    dp[u][1] = color[u] == 1;
    dp[u][0] = color[u] == 0;

    for (auto& v : graph[u]) {
        dp[u][1] =
            (dp[u][0] * dp[v][1] + dp[u][1] * dp[v][0] + dp[v][1] * dp[u][1]) %
            M;
        dp[u][0] = (dp[u][0] * dp[v][0] + dp[v][1] * dp[u][0]) % M;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        graph[p].emplace_back(i);
    }
    for (int i = 0; i < n; ++i) cin >> color[i];

    dfs();

    cout << dp[0][1] << '\n';
    // for (int i = 0; i < n; ++i) cerr << dp[i][0] << ' ' << dp[i][1] << '\n';

    return 0;
}