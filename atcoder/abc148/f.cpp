#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define vi vector<int>
#define vvi vector<vector<int>>
#define se second

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N = 1e5 + 7, n, U, V, res = 0;
vvi g(N);
vi in(N);
vi dis(N);

void dfsu(int u, int s = 0) {
    if (in[u]) return;
    in[u] = 1;
    dis[u] = s;
    for (auto& v : g[u]) dfsu(v, s + 1);
}

void dfsv(int u, int s = 0) {
    if (in[u]) return;
    in[u] = 1;
    // cout << u << ' ' << s << ' ' << dis[u] << '\n';

    bool isleaf = true;

    for (auto& v : g[u]) dfsv(v, s + 1);

    if(dis[u] < s){

    }
}

void solve() {
    cin >> n >> U >> V;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfsu(U);
    in.assign(N, 0);
    dfsv(V);
    cout << res << '\n';
    // for (int i = 1; i <= n; ++i) cout << dis[i] << " \n"[i == n];
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}