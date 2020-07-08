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

    int n, m, M = 1e9 + 7;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                g[i][j] = 0;
                continue;
            }
            if (i && !j) g[i][j] = g[i - 1][j];
            if (!i && j) g[i][j] = g[i][j - 1];
            if (i && j) g[i][j] = (g[i - 1][j] + g[i][j - 1]) % M;
        }
    cout << g[n - 1][m - 1] << '\n';

    return 0;
}