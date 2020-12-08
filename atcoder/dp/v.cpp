#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int M;
const int N = 1e5 + 7;
vvi g(N);
vi pas(N), res(N, -1), par(N), up(N, 1);

int dfs(int u = 1) {
    res[u] = 1;
    for (auto &v : g[u])
        if (res[v] == -1) res[u] = 1LL * res[u] * (dfs(v) + 1) % M;
    return res[u];
}
void cal(int u = 1) {
    // cout << "cal " << u << '\n';
    pas[u] = 1;
    vi gra(1, -1), pre(1, 1), suf(1, 1);
    for (auto &v : g[u])
        if (!pas[v]) {
            gra.push_back(v);
            pre.push_back((res[v] + 1) % M);
            suf.push_back((res[v] + 1) % M);
        }
    gra.push_back(-1);
    pre.push_back(1);
    suf.push_back(1);

    int n = gra.size() - 2;
    for (int i = 1; i <= n; ++i) pre[i] = 1LL * pre[i] * pre[i - 1] % M;
    for (int i = n; i; i--) suf[i] = 1LL * suf[i] * suf[i + 1] % M;

    for (int i = 1; i <= n; ++i)
        up[gra[i]] = (1LL * up[u] * pre[i - 1] % M * suf[i + 1] % M + 1) % M;

    for (int i = 1; i <= n; ++i) cal(gra[i]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n >> M;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();
    cal();

    for (int i = 1; i <= n; ++i)
        cout << 1LL * up[i] * res[i] % M << " \n"[i == n];

    return 0;
}
