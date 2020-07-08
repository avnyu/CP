#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iiii tuple<int, int, int, int>
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

int cal(vector<vi>& a, int x, int y) {
    for (auto& i : a)
        for (auto& j : i)
            if (j != -1) j = 0;

    queue<iii> q;
    q.push(iii{x, y, 1});

    int u, v, c, res = 0;
    while (!q.empty()) {
        tie(u, v, c) = q.front();
        q.pop();

        if (u < 0 || u == a.size() || v < 0 || v == a[0].size() || a[u][v]) continue;
        a[u][v] = c;
        res = max(res, c);

        for (int i = -1; i < 2; i += 2) {
            q.push(iii{u + i, v, c + 1});
            q.push(iii{u, v + i, c + 1});
        }
    }
    return res - 1;
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vi> a(h, vi(w, 0));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            if (c == '#') a[i][j] = -1;
        }
    int res = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == -1) continue;
            res = max(res, cal(a, i, j));
        }
    cout << res << '\n';
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}