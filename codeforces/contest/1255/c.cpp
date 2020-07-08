#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve() {
    int n, N = 1e5 + 7;
    cin >> n;

    vector<vector<int>> graph(N);
    vector<int> deg(N, 0);

    for (int i = 0; i < n - 2; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(v);
        graph[u].push_back(w);
        graph[v].push_back(u);
        graph[v].push_back(w);
        graph[w].push_back(u);
        graph[w].push_back(v);

        deg[u] += 1;
        deg[v] += 1;
        deg[w] += 1;
    }

    set<pair<int, int>> s;
    for (int i = 0; i < N; ++i)
        if (deg[i] == 1) {
            s.insert({deg[i], i});
            break;
        }

    for (int i = 0; i < n; ++i) {
        int u = s.begin()->second;
        s.erase(s.begin());

        cout << u << ' ';
        deg[u] = -2;
        for (auto& v : graph[u]) {
            if (s.find(make_pair(deg[v], v)) != s.end())
                s.erase(make_pair(deg[v], v));

            deg[v]--;
            if (deg[v] >= -1) s.insert({deg[v], v});
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}