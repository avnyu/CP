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

int lcs(string& a, string& b) {
    int n = a.size(), k = 1e3, i, j, K = 2e3 + 7;
    vector<vector<int>> dp(2, vector<int>(K));

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    return L[n][n];
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    string a, b, res[2] = {"Long lost brothers D:\n", "Not brothers :(\n"};
    cin >> a >> b;
    int n = a.size();
    int reg = ceil(double(0.99) * n);

    cout << res[lcs(a, b) < reg] << '\n';

    return 0;
}