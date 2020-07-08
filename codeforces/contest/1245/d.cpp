#include <bits/stdc++.h>
using namespace std;

int N = 2e3 + 7;
int n, C = 1e9;
vector<vector<int>> a(N, vector<int>(2, 0));
vector<int> k(N), c(N), par(N, -1);

int root(int u) { return par[u] < 0 ? u : (par[u] = root(par[u])); }

void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (c[u] > c[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> k[i];

    priority_queue<tuple<int, int, int>> q;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            long long cij = 1LL * (k[i] + k[j]) *
                            (abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]));
            if (cij > C) continue;
            q.push(make_tuple(int(-cij), i, j));
        }

    vector<pair<int, int>> res_e;
    long long res = 0;
    for (int i = 0; i < n; ++i) res += c[i];

    while (!q.empty()) {
        int cij, i, j;
        tie(cij, i, j) = q.top();
        cij = -cij;
        q.pop();

        int ri = root(i), rj = root(j);
        if (ri != rj && cij < max(c[ri], c[rj])) {
            res_e.push_back({i + 1, j + 1});
            merge(ri, rj);
            res += cij - max(c[ri], c[rj]);
        }
    }
    vector<int> res_v(n);
    for (int i = 0; i < n; ++i) res_v[i] = root(i) + 1;

    sort(res_v.begin(), res_v.end());
    res_v.erase(unique(res_v.begin(), res_v.end()), res_v.end());

    cout << res << '\n';
    cout << res_v.size() << '\n';
    for (auto& i : res_v) cout << i << ' ';
    cout << '\n';
    cout << res_e.size() << '\n';
    for (auto& i : res_e) cout << i.first << ' ' << i.second << '\n';

    return 0;
}