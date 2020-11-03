#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));
    unordered_map<int, int> index;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        index[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = cnt[i - 1][j] + (a[i] == a[j]);
        }
    }

    long long res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            int ak = a[j] + a[j] - a[i];
            int k = index[ak];
            res += cnt[n][k] - cnt[j][k];
        }
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}