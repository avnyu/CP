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

bool check(int s[9][9], int x, int y, int v) {
    int bx = x / 3, by = y / 3;
    for (int i = 0; i < 9; ++i)
        if (s[x][i] == v || s[i][y] == v) return false;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (s[bx * 3 + i][by * 3 + j] == v) return false;
    return true;
}

void out(int s[9][9]) {
    system("clear");
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) cout << s[i][j] << " \n"[j == 8];
}

bool term = false;

void dfs(int s[9][9], int t) {
    if (t == 81) {
        out(s);
        term = true;
        return;
    }
    if (term) return;
    int x = t / 9, y = t % 9;
    if (s[x][y]) return dfs(s, t + 1);
    for (int i = 1; i < 10; ++i)
        if (check(s, x, y, i)) {
            s[x][y] = i;
            out(s);
            dfs(s, t + 1);
            if (term) break;
            s[x][y] = 0;
        }
    return;
}
void solve() {
    int s[9][9] = {};
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) cin >> s[i][j];
    chrono::steady_clock sc;
    auto start = sc.now();
    dfs(s, 0);
    auto end = sc.now();
    // system("clear");
    // out(s);
    auto time_span = static_cast<chrono::duration<double>>(end - start);
    cout << "Time " << time_span.count() << "s.\n";
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}