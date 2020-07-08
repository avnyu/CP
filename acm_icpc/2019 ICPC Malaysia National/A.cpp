#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void rotate_left(vector<vector<char>>& a) {
    int n = a.size();
    vector<vector<char>> b(n, vector<char>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[j][n - 1 - i];
            if (b[i][j] == '<')
                b[i][j] = 'v';
            else if (b[i][j] == 'v')
                b[i][j] = '>';
            else if (b[i][j] == '>')
                b[i][j] = '^';
            else if (b[i][j] == '^')
                b[i][j] = '<';
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) a[i][j] = b[i][j];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 0;
    for (auto& i : s) x = (x + (i == 'R' ? -1 : 1) + 4) % 4;

    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];

    while (x--) rotate_left(a);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cout << a[i][j] << (j == n - 1 ? "\n" : "");

    return 0;
}