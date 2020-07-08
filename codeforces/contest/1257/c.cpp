#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, M = 1e9;
    cin >> t;
    vector<vector<int>> cnt(2e5 + 7);
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]].push_back(i);
        }

        int mn = M;
        for (int i = 0; i < n; ++i) {
            if (int(cnt[a[i]].size()) < 2) {
                cnt[a[i]].clear();
                continue;
            }
            for (int j = 1; j < cnt[a[i]].size(); ++j)
                mn = min(cnt[a[i]][j] - cnt[a[i]][j - 1] + 1, mn);
            cnt[a[i]].clear();
        }
        cout << (mn != M ? mn : -1) << '\n';
    }
    return 0;
}