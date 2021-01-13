#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    const int M = 1e9 + 7;
    int e[k + 1][n], cnt[n], a[n];
    memset(e, 0, sizeof e);
    memset(cnt, 0, sizeof cnt);
    memset(a, 0, sizeof a);

    for (int j = 0; j < n; ++j) e[0][j] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) e[i][j] = (e[i][j] + e[i - 1][j - 1]) % M;
            if (j < n - 1) e[i][j] = (e[i][j] + e[i - 1][j + 1]) % M;
        }
    }
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j < n; ++j)
            cnt[j] = (1LL * e[i][j] * e[k - i][j] + cnt[j]) % M;

    // for (int i = 0; i < n; ++i) cout << cnt[i] << " \n"[i == n - 1];

    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res = (1LL * cnt[i] * a[i] + res) % M;
    }

    for (int i, x; q--;) {
        cin >> i >> x;
        --i;
        res = (1LL * cnt[i] * (x - a[i] + M) + res) % M;
        a[i] = x;
        cout << res << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int t = 1;
    // cin >> t;
    for (; t--;) solve();

    return 0;
}