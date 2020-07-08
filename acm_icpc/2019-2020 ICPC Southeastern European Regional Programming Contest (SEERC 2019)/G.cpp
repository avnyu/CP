#include <bits/stdc++.h>
using namespace std;

int h, n, m, len_row, len_col;
vector<vector<char>> front, side;
vector<tuple<int, int, int>> res_max, res_min;
vector<int> row(100, -1), col(100, -1);

bool chk() {
    for (int i = 0; i < h; ++i) {
        len_row = len_col = 0;

        for (int j = 0; j < n; ++j)
            if (front[i][j] == '1') row[len_row++] = j;

        for (int k = 0; k < m; ++k)
            if (side[i][k] == '1') col[len_col++] = k;

        if (!len_col && len_row) return false;
        if (!len_row && len_col) return false;
    }
    return true;
}

void find_max() {
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                if (front[i][j] == '1' && side[i][k] == '1')
                    res_max.push_back({i, j, k});
}

void find_min() {
    for (int i = 0; i < h; ++i) {
        len_row = len_col = 0;

        for (int j = 0; j < n; ++j)
            if (front[i][j] == '1') row[len_row++] = j;

        for (int k = 0; k < m; ++k)
            if (side[i][k] == '1') col[len_col++] = k;

        while (len_row) {
            res_min.push_back({i, row[len_row - 1], col[len_col - 1]});

            if (len_col == 1 && len_row == 1) break;

            len_col = max(1, len_col - 1);
            len_row = max(1, len_row - 1);
        }
    }
    sort(res_min.begin(), res_min.end());
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> h >> n >> m;
    front.assign(h, vector<char>(n));
    side.assign(h, vector<char>(m));

    for (auto& i : front)
        for (auto& j : i) cin >> j;
    for (auto& i : side)
        for (auto& j : i) cin >> j;

    if (!chk()) {
        cout << "-1\n";
        return 0;
    }

    find_max();
    find_min();

    cout << res_max.size() << '\n';
    for (auto& i : res_max)
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';

    cout << res_min.size() << '\n';
    for (auto& i : res_min)
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';

    return 0;
}