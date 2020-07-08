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
    // freopen("in", "r", stdin);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size(), N = 2e2 + 7, M = 1e9 + 7, i, j, k;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(N, M)));
    vector<vector<vector<int>>> pr(n + 1, vector<vector<int>>(m + 1, vector<int>(N, M)));

    s += '.';
    t += '.';
    dp[0][0][0] = 0;
    for (i = 0; i <= n; ++i)
        for (j = 0; j <= m; ++j)
            for (k = 0; k < N; ++k) {
                if (dp[i][j][k] == M) continue;
                int ni, nj;

                ni = i + (s[i] == '(');
                nj = j + (t[j] == '(');
                if (k < N - 1 && dp[ni][nj][k + 1] > dp[i][j][k] + 1) {
                    dp[ni][nj][k + 1] = dp[i][j][k] + 1;
                    pr[ni][nj][k + 1] = 1 + (ni - i) * 2 + (nj - j) * 4;
                }

                ni = i + (s[i] == ')');
                nj = j + (t[j] == ')');
                if (k && dp[ni][nj][k - 1] > dp[i][j][k] + 1) {
                    dp[ni][nj][k - 1] = dp[i][j][k] + 1;
                    pr[ni][nj][k - 1] = (ni - i) * 2 + (nj - j) * 4;
                }
            }

    k = M;
    for (i = 0; i < N; ++i) k = min(k, dp[n][m][i] + i);
    for (i = 0; i < N; ++i)
        if (k == dp[n][m][i] + i) {
            k = i;
            break;
        }

    string res(k, ')');
    while (n || m || k) {
        int nn = n, nm = m, nk = k;
        // cout << n << ' ' << m << ' ' << k << ' ' << pr[n][m][k] << '\n';

        if (pr[n][m][k] & 1) {
            res += '(';
            nk--;
        } else {
            res += ')';
            nk++;
        }

        if (pr[n][m][k] & 2) nn--;
        if (pr[n][m][k] & 4) nm--;

        n = nn;
        m = nm;
        k = nk;
    }

    reverse(res.begin(), res.end());

    cout << res << '\n';

    return 0;
}