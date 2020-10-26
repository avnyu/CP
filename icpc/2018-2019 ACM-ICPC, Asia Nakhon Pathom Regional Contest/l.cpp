#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    ++n;
    ++m;
    int ans = 0;
    vector<vector<char>> a(n, vector<char>(m, '0'));
    for (int x = 1; x < n; ++x) {
        for (int y = 1; y < m; ++y) {
            cin >> a[x][y];
            a[x][y] =
                a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1] + a[x][y] - '0';
        }
    }
    for (int x = 1; x < n; ++x) {
        for (int y = ans; y < m; ++y) {
            int lef = ans + 1, rig = min(x, y);
            while (lef <= rig) {
                int mid = (lef + rig) >> 1;
                if (a[x][y] - a[x - mid][y] - a[x][y - mid] +
                        a[x - mid][y - mid] <
                    2) {
                    ans = mid;
                    lef = mid + 1;
                } else {
                    rig = mid - 1;
                }
            }
        }
        x = max(x, ans);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    // cerr << fixed << setprecision(5) << double(clock()) * 1000 /
    // CLOCKS_PER_SEC
    //      << " ms\n";
    return 0;
}