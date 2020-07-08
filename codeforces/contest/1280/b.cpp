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
    int r, c;
    cin >> r >> c;
    bool istrue = true;
    bool isfalse = true;
    vector<vector<char>> a(r, vector<char>(c));

    for (auto& i : a)
        for (auto& j : i) {
            cin >> j;
            j = (j == 'A');
            istrue &= j;
            isfalse &= (!j);
        }

    if (istrue) {
        cout << "0\n";
        return;
    }
    if (isfalse) {
        cout << "MORTAL\n";
        return;
    }

    auto check_row = [](vector<vector<char>>& a, int r) {
        int c = a[0].size();
        bool chk = true;
        for (int i = 0; i < c; ++i) chk &= a[r][i];
        return chk;
    };
    auto check_col = [](vector<vector<char>>& a, int c) {
        int r = a.size();
        bool chk = true;
        for (int i = 0; i < r; ++i) chk &= a[i][c];
        return chk;
    };

    if (check_row(a, 0) || check_row(a, r - 1) || check_col(a, 0) || check_col(a, c - 1)) {
        cout << "1\n";
        return;
    }

    if (a[0][0] || a[r - 1][0] || a[0][c - 1] || a[r - 1][c - 1]) {
        cout << "2\n";
        return;
    }

    for (int i = 1; i < r - 1; ++i)
        if (check_row(a, i)) {
            cout << "2\n";
            return;
        }

    for (int i = 1; i < c - 1; ++i)
        if (check_col(a, i)) {
            cout << "2\n";
            return;
        }

    for (int i = 1; i < c - 1; ++i)
        if (a[0][i] || a[r - 1][i]) {
            cout << "3\n";
            return;
        }

    for (int i = 1; i < r - 1; ++i) {
        if (a[i][0] || a[i][c - 1]) {
            cout << "3\n";
            return;
        }
    }

    cout << "4\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}