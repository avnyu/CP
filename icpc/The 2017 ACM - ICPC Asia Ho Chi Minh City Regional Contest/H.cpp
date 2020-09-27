#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define iii tuple<int, int, int>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<ii>> row(n, vector<ii>(m));
    vector<vector<ii>> col(m, vector<ii>(n));
    vector<vector<int>> res(n, vector<int>(m, 1));
    vector<iii> node(n * m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            row[i][j] = {x, j};
            col[j][i] = {x, i};
            node[i * m + j] = {x, i, j};
        }
    for (auto& i : row) sort(i.begin(), i.end());
    for (auto& i : col) sort(i.begin(), i.end());
    sort(node.begin(), node.end());

    for (auto& t : node) {
        int x, i, j;
        tie(x, i, j) = t;

        int ni = upper_bound(col[j].begin(), col[j].end(), ii{x, i}) -
                 col[j].begin();
        //cout << i << ' ' << j << ' ';

        if (ni != n) {
            ii nix = col[j][ni];
            ni = nix.se;
            //cout << "ni " << ni << ' ';
            res[ni][j] = max(res[ni][j], res[i][j] + (nix.fi > x));
        }

        int nj = upper_bound(row[i].begin(), row[i].end(), ii{x, j}) -
                 row[i].begin();
        if (nj != m) {
            ii njx = row[i][nj];
            nj = njx.se;
            //cout << "nj " << nj << ' ';
            res[i][nj] = max(res[i][nj], res[i][j] + (njx.fi > x));
        }
        // cout << '\n';
    }

    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < m; ++j) cout << res[i][j] << " \n"[j == m - 1];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) res[0][0] = max(res[0][0], res[i][j]);
    cout << res[0][0] << '\n';

    return 0;
}