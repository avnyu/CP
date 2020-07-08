#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int N = 1e3 + 7;
int n, m;
vector<vector<int>> st(N, vector<int>(N << 2, N));

int upd(int col, int p, int v, int i = 1, int l = 0, int r = n - 1) {
    if (p < l || p > r) return st[col][i];
    if (p == l && p == r) return st[col][i] = v;
    int md = (l + r) >> 1;
    return st[col][i] = min(upd(col, p, v, i << 1, l, md),
                            upd(col, p, v, i << 1 | 1, md + 1, r));
}
int get(int col, int b, int e, int i = 1, int l = 0, int r = n - 1) {
    if (b > r || e < l) return N;
    if (b <= l && r <= e) return st[col][i];
    int md = (l + r) >> 1;
    return min(get(col, b, e, i << 1, l, md),
               get(col, b, e, i << 1 | 1, md + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m + 1, '.'));
    vector<vector<int>> cnt(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = m - 1; j >= 0; --j) {
            cnt[i][j] = 1 + (a[i][j] == a[i][j + 1]) * cnt[i][j + 1];
            upd(j, i, cnt[i][j]);
        }

    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int l = i, r = n - 1;

            while (l <= r) {
                int md = (l + r) >> 1;
                int width = get(j, i, md);
                // cout << i << ' ' << j << ' ' << md << ' ' << width << '\n';

                if (width >= md - i + 1) {
                    res = max(res, md - i + 1);
                    l = md + 1;
                } else
                    r = md - 1;
            }
        }

    cout << res * res << '\n';
    // cout << get(0, 0, 1) << '\n';

    return 0;
}