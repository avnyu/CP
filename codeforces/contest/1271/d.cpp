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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(3));
    vector<vector<ii>> g(n);
    vector<int> spare(n), max_par(n);
    iota(max_par.begin(), max_par.end(), 0);
    for (auto& i : a)
        for (auto& j : i) cin >> j;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        max_par[v] = max(max_par[v], u);
        g[u].push_back({a[v][2], v});
    }
    for (int i = 0; i < n; ++i) g[i].push_back({a[i][2], i});

    for (int i = 0; i < n; ++i) {
        if (k < a[i][0]) {
            cout << "-1\n";
            return;
        }
        k += a[i][1];
        a[i][1] = 0;
        int need = (i < n - 1 ? a[i + 1][0] : 0);
        spare[i] = k - need;
    }
    for (int i = n - 1; i--;) spare[i] = min(spare[i], spare[i + 1]);

    // for (auto& i : g)
    //     for (int j = 0; j < i.size(); ++j) cout << i[j].se << " \n"[j == i.size() - 1];
    // for (auto& i : a)
    //     for (int j = 0; j < 3; ++j) cout << i[j] << " \n"[j == 2];

    set<ii> in;
    for (int i = 0; i < n; ++i) {
        for (auto& iiv : g[i]) {
            int v = iiv.se;
            if (a[v][1]) continue;
            if (max_par[v] != i) continue;
            a[v][1] = 1;
            in.insert(iiv);
        }
        while (in.size() > spare[i]) {
            int v = in.begin()->se;
            a[v][1] = 0;
            in.erase(in.begin());
        }
    }

    // for (int i = 0; i < n; ++i) cout << spare[i] << " \n"[i == n - 1];
    // for (auto& i : a)
    //     for (int j = 0; j < 3; ++j) cout << i[j] << " \n"[j == 2];

    int res = 0;
    for (auto& i : a) res += i[1] * i[2];
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}