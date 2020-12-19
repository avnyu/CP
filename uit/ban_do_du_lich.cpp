#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> res;

    if (n == 1 && m == 0) {
        cout << "Possible\n";
        return 0;
    } else if (n == m) {
        res.push_back({1, n});
        for (int i = 1; i < n; ++i) res.push_back({i, i + 1});
    } else if (n * (n - 1) / 2 == m) {
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) res.push_back({i + 1, j + 1});
    } else if (n % 2 == 0 && m == n * n / 4) {
        for (int i = 0; i < n / 2; ++i)
            for (int j = n / 2; j < n; ++j) res.push_back({i + 1, j + 1});
    }

    if (res.empty())
        cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for (auto& i : res) cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}