#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define iii tuple<int, int, int>
#define ii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, q;
    cin >> n >> q;
    int link = 0;
    vvi save(2, vi(n + 7, 0));
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r -= 1;
        save[r][c] ^= 1;
        if (save[r][c]) {
            link -= save[r ^ 1][c - 1];
            link -= save[r ^ 1][c];
            link -= save[r ^ 1][c + 1];
        } else {
            link += save[r ^ 1][c - 1];
            link += save[r ^ 1][c];
            link += save[r ^ 1][c + 1];
        }
        cout << (link ? "No\n" : "Yes\n");
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}