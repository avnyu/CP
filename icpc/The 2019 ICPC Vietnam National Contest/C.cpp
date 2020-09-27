#include <bits/stdc++.h>
using namespace std;

int a, b, c, m;

void solve() {
    vector<vector<int>> point(m, vector<int>(3, 0));
    vector<vector<int>> block(m, vector<int>(6, 0));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < 3; ++j) cin >> point[i][j];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < 6; ++j) cin >> block[i][j];

    bool chk = true;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < 3; ++j)
            chk &=
                (block[i][j] <= point[i][j] && point[i][j] <= block[i][j + 3]);

    long long res = 1LL * a * b * c;
    for (int i = 0; i < m; ++i) {
        long long res_bi = 1;
        for (int j = 0; j < 3; ++j) {
            res_bi = res_bi * (block[i][j + 3] - block[i][j] + 1);
        }
        res -= res_bi;
    }
    chk &= (res == 0LL);

    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j) {
            bool intersect = true;
            for (int k = 0; k < 3; ++k) {
                int mxl = max(block[i][k], block[j][k]);
                int mnr = min(block[i][k + 3], block[j][k + 3]);
                intersect &= (mxl <= mnr);
            }
            chk &= (!intersect);
        }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            int mx;
            if (j == 0)
                mx = a;
            else if (j == 1)
                mx = b;
            else
                mx = c;

            chk &= (1 <= block[i][j]) & (block[i][j] <= block[i][j + 3]) &
                   (block[i][j + 3] <= mx);
        }
    }

    cout << (chk ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    while (1) {
        cin >> a;
        if (a == -1) break;

        cin >> b >> c >> m;
        solve();
    }

    return 0;
}