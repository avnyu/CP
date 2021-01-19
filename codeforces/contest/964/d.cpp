#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
vector<set<int>> g(N);
vector<int> deg(N), out(N, 0), pas(N);
vector<int> res;

void des(int u, int p) {
    res.push_back(u);
    out[u] = 1;
    deg[u] = 0;

    for (auto &v : g[u]) {
        deg[v]--;
        // cout << "deg " << v << " -1\n";
    }
    for (auto &v : g[u])
        if (v != p && deg[v] % 2 == 0 && out[v] == 0) des(v, u);
}
void dfs(int u, int p) {
    if (pas[u]) return;
    pas[u] = 1;

    for (auto &v : g[u])
        if (v != p) dfs(v, u);

    if (deg[u] % 2 == 0 && out[u] == 0) {
        // cout << "Des from " << u << '\n';
        des(u, p);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1, p; i <= n; ++i) {
        cin >> p;
        if (p > 0) {
            g[p].insert(i);
            g[i].insert(p);

            deg[p]++;
            deg[i]++;
        }
    }

    if (n & 1) {
        dfs(1, -1);

        cout << "YES\n";
        if (n != (int)res.size()) cout << res.size() << '\n';
        for (int i = 0; i < (int)res.size(); ++i) cout << res[i] << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}