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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("in", "r", stdin);

    const int N = 307;
    vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(N)));
    vector<vector<vector<int>>> div(N, vector<vector<int>>(N, vector<int>(N)));
    int n, cnt[4] = {};

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    queue<iii> q;
    int c1 = cnt[1], c2 = cnt[2], c3 = cnt[3];
    div[c1][c2][c3] = 1;
    q.push({c1, c2, c3});

    double res = 0, dn = n;
    while (!q.empty()) {
        tie(c1, c2, c3) = q.front();
        q.pop();
        dp[c1][c2][c3] /= div[c1][c2][c3];
        std::cout << c1 << ' ' << c2 << ' ' << c3 << " - " << dp[c1][c2][c3] << ' ' << div[c1][c2][c3] << '\n';
        if (c3) {
            if (!div[c1][c2 + 1][c3 - 1]) q.push({c1, c2 + 1, c3 - 1});
            div[c1][c2 + 1][c3 - 1]++;
            dp[c1][c2 + 1][c3 - 1] += dp[c1][c2][c3] + dn / c3;
        }
        if (c2) {
            if (!div[c1 + 1][c2 - 1][c3]) q.push({c1 + 1, c2 - 1, c3});
            div[c1 + 1][c2 - 1][c3]++;
            dp[c1 + 1][c2 - 1][c3] += dp[c1][c2][c3] + dn / c2;
        }
        if (c1) {
            if (!div[c1 - 1][c2][c3]) q.push({c1 - 1, c2, c3});
            div[c1 - 1][c2][c3]++;
            dp[c1 - 1][c2][c3] += dp[c1][c2][c3] + dn / c1;
        }
    }

    std::cout << fixed << setprecision(18) << dp[0][0][0] / div[0][0][0] << '\n';
    return 0;
}