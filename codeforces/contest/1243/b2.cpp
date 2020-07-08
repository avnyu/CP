#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        vector<int> cnt(128, 0);
        for (auto& i : s) cnt[i]++;
        for (auto& i : t) cnt[i]++;

        bool chk = true;
        for (auto& i : cnt)
            if (i & 1) chk = false;

        if (!chk) {
            cout << "No\n";
            continue;
        }

        vector<pair<int, int>> res;

        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) {
                s[i] = t[i] = '.';
                continue;
            }

            bool chk = false;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == s[i]) {
                    chk = true;
                    res.push_back({j, i});
                    swap(t[i], s[j]);

                    s[i] = t[i] = '.';
                    break;
                }
            }

            if (chk) continue;

            for (int j = i + 1; j < n; ++j) {
                if (t[j] == s[i]) {
                    res.push_back({j, j});
                    swap(s[j], t[j]);
                    res.push_back({j, i});
                    swap(s[j], t[i]);

                    s[i] = t[i] = '.';
                    break;
                }
            }
        }

        cout << "Yes\n";
        cout << res.size() << '\n';
        for (auto& i : res) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }

    return 0;
}