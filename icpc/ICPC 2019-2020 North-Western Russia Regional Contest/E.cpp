#include <bits/stdc++.h>
using namespace std;

int N = 2e5 + 7;
int n, m, r;
vector<int> par(N, 0), height(N, 0), team(N);
vector<vector<int>> graph(N);

void dfs(int u, int p) {
    if (height[u]) return;
    height[u] = height[p] + 1;
    par[u] = p;

    for (auto& v : graph[u]) dfs(v, u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < m; ++i) cin >> team[i];

    if (m == 1) {
        cout << "YES\n" << team[0] << '\n';
        return 0;
    }

    dfs(team[0], 0);

    int chosen = 0;
    for (int i = 0; i < m; ++i)
        if (height[team[i]] > height[chosen]) chosen = team[i];

    int dis = height[chosen] - height[team[0]];
    if (dis & 1) {
        cout << "NO\n";
        return 0;
    }

    dis >>= 1;
    while (dis--) chosen = par[chosen];

    height.assign(N, 0);
    dfs(chosen, 0);

    for (int i = 0; i < m; ++i)
        if (height[team[i]] != height[team[0]]) {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    cout << chosen << '\n';

    return 0;
}