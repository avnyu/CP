#include <bits/stdc++.h>
using namespace std;

int n, m, res = 0;
vector<set<int>> g(1e5 + 7);
set<int> s;

void dfs(int u) {
    s.erase(u);

    auto it = s.begin();
    while (it != s.end()) {
        int v = *it;
        if (g[u].find(v) == g[u].end()) dfs(v);
        it = s.upper_bound(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 0; i < n; ++i) s.insert(i);

    for (int i = 0; i < n; ++i) {
        if (s.find(i) != s.end()) {
            dfs(i);
            ++res;
        }
    }

    cout << res - 1 << '\n';

    return 0;
}