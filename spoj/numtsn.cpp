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

const int M = 1e9 + 7;
string a, b;
int na, n;
vi cnt(4, 0);
int dp[18][18][18][52];

void add(int x, int v) {
    if (x == 3)
        cnt[0] += v;
    else if (x == 6)
        cnt[1] += v;
    else if (x == 9)
        cnt[2] += v;
    else
        cnt[3] += v;
}

void get(int p = 0, int l = 0, int r = 0) {
    if (l != -1 && r != -1 && p < n) {
        for (auto i = a[p]; i <= b[p]; ++i) {
            int nl = (i == a[p] ? a[p] - 48 : -1);
            int nr = (i == b[p] ? b[p] - 48 : -1);

            add(i - 48, 1);
            get(p + 1, nl, nr);
            add(i - 48, -1);
        }
    } else if (l != -1 && p < n) {
        for (auto i = a[p]; i <= '9'; ++i) {
            int nl = (i == a[p] ? a[p] - 48 : -1);

            add(i - 48, 1);
            get(p + 1, nl, r);
            add(i - 48, -1);
        }
    } else if (r != -1 && p < n) {
        for (auto i = '0'; i <= b[p]; ++i) {
            int nr = (i == b[p] ? b[p] - 48 : -1);

            add(i - 48, 1);
            get(p + 1, l, nr);
            add(i - 48, -1);
        }
    } else if (cnt[0] < 18 && cnt[1] < 18 && cnt[2] < 18)
        dp[cnt[0]][cnt[1]][cnt[2]][cnt[3]] += 1;
}

void solve() {
    cin >> a >> b;
    na = a.size();
    n = b.size();

    while (na < n) {
        na++;
        a = "0" + a;
    }

    // cout << a << ' ' << b << '\n';

    memset(dp, 0, sizeof dp);
    get();

    // cout << "pass get\n";

    for (int i = 0; i < 17; ++i)
        for (int j = 0; j < 17; ++j)
            for (int k = 0; k < 17; ++k)
                for (int l = 0; l <= n - i - j - k; ++l) {
                    dp[i + 1][j][k][l] =
                        (dp[i + 1][j][k][l] + dp[i][j][k][l]) % M;

                    dp[i][j + 1][k][l] =
                        (dp[i][j + 1][k][l] + dp[i][j][k][l]) % M;

                    dp[i][j][k + 1][l] =
                        (dp[i][j][k + 1][l] + dp[i][j][k][l]) % M;

                    dp[i][j][k][l + 1] =
                        (dp[i][j][k][l + 1] + (7LL * dp[i][j][k][l]) % M) % M;
                }

    int res = 0;
    for (int i = 1; i + i + i <= n; ++i)
        res = (res + dp[i][i][i][n - i - i - i]) % M;

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
