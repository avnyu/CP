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
    int n, m;
    cin >> n >> m;
    int a[501][501];
    if (n == 1 && m == 1) {
        cout << "0\n";
        return;
    }
    bool chk = false;
    if (n > m) {
        swap(n, m);
        chk = true;
    }
    for (int j = 0; j < m; ++j) a[0][j] = 2 + j;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j) a[i][j] = (m + 1 + i) * a[0][j];
    if (chk) {
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                cout << a[i][j] << " \n"[i == n - 1];
        return;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cout << a[i][j] << " \n"[j == m - 1];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    solve();

    return 0;
}