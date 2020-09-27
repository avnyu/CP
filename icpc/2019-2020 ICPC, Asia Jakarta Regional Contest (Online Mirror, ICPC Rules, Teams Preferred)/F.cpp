#include <bits/stdc++.h>
using namespace std;

int N = 4e3 + 7;
int n;
vector<vector<int>> graph(N);
vector<vector<int>> part(N);
vector<vector<int>> sub(N);
vector<int> in(N);
vector<int> deg(N);
vector<bool> visited(N);

int dfs_cnt(int u) {
    if (visited[u]) return 0;
    visited[u] = 1;

    int res = 1;
    for (auto& v : graph[u]) {
        int cnt_v = dfs_cnt(v);
        if (cnt_v) part[u].push_back(cnt_v);
        res += cnt_v;
    }

    if (res != n) part[u].push_back(n - res);
    return res;
}

int split() {
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) continue;

        int x = part[i][0];
        bool chk = true;
        for (auto& v : part[i]) chk &= v == x;

        if (chk) return i;
    }
    return 0;
}

void dfs(int u, int t) {
    if (visited[u]) return;
    visited[u] = true;

    sub[t].push_back(deg[u]);
    for (auto& v : graph[u]) dfs(v, t);
}

void compare(int u) {
    int i = 0;
    for (auto& v : graph[u]) {
        deg[v]--;
        dfs(v, i);
        sort(sub[i].begin(), sub[i].end());
        i++;
    }
    for (i = 1; i < deg[u]; ++i) {
        int l = sub[i].size();
        for (int j = 0; j < l; ++j)
            if (sub[i][j] != sub[i - 1][j]) {
                cout << "-1\n";
                return;
            }
    }
    cout << deg[u] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in", "r", stdin);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    dfs_cnt(1);
    int u = split();
    if (!u) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < N; ++i) visited[i] = false;
    compare(u);

    return 0;
}