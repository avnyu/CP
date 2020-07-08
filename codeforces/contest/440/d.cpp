#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 4e2 + 7;
int n, k, res_len, from;
vector<vector<int>> dp(N, vector<int>(N, N)), graph(N);
vector<vector<int>> edge_index(N, vector<int>(N));
vector<int> par(N), res(N);

void cal(int u, int v) {
    for (int us = k; us; --us) {
        dp[u][us]++;

        for (int vs = 1; vs < us; ++vs)
            dp[u][us] = min(dp[u][us], dp[u][us - vs] + dp[v][vs]);
    }
}

void dfs(int u = 1, int prv = 0) {
    par[u] = prv;
    for (auto& v : graph[u])
        if (v != prv) dfs(v, u);

    dp[u][1] = 0;
    for (auto& v : graph[u])
        if (v != prv) cal(u, v);
}

void trace(int u = 1, int prv = 0, int k_rm = k) {
    cout << "trace " << u << ' ' << prv << ' ' << k_rm << '\n';

    for (int j = graph[u].size() - 1; j >= 0; --j) {
        int v = graph[u][j];
        if (v == prv) continue;

        bool traced = false;
        for (int vs = k_rm - 1; vs; --vs) {
            if (dp[u][k_rm] == dp[u][k_rm - vs] + dp[v][vs]) {
                k_rm -= vs;
                traced = true;
                trace(v, u, vs);
                break;
            }
        }

        if (!traced) {
            cout << "cut " << u << ' ' << v << ' ' << edge_index[u][v] << '\n';
            res[res_len++] = edge_index[u][v];
            for (int i = 1; i <= k_rm; ++i) dp[u][i]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("in", "r", stdin);

    cin >> n >> k;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        edge_index[u][v] = edge_index[v][u] = i;
    }

    dfs();

    res_len = 0;
    from = 1;

    for (int i = 2; i <= n; ++i)
        if (dp[i][k] + 1 < dp[from][k] + (from != 1)) from = i;

    if (from != 1) res[res_len++] = edge_index[from][par[from]];
    cout << from << ' ' << k << ' ' << dp[from][k] << '\n';

    trace(from, par[from], k);
    for (int i = 0; i < res_len; ++i) cout << res[i] << " \n"[i == res_len - 1];

    cerr << "debug\n";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) cerr << dp[i][j] << " \n"[j == k];

    return 0;
}