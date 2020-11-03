#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    freopen("in", "r", stdin);

    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<int> score(c);

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) cin >> grid[i][j];
    for (int i = 0; i < c; ++i) cin >> score[i];

    vector<vector<int>> g(c);
    vector<vector<int>> out(r, vector<int>(c, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < c; ++i) {
        cout << i << '\n';
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < c; ++k) out[j][k] = 0;

        q.push({0, i});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if (x == r) {
                g[i].push_back(y);
                continue;
            }

            if (y < 0 || y == c) continue;

            if (out[x][y]) continue;
            out[x][y] = 1;

            if (grid[x][y] == '.')
                q.push({x + 1, y});
            else if (grid[x][y] == 'X')
                continue;
            else if (grid[x][y] == 'R')
                q.push({x, y + 1});
            else if (grid[x][y] == 'L')
                q.push({x, y - 1});
            else {
                q.push({x, y + 1});
                q.push({x, y - 1});
            }
        }
        cout << "end " << i << '\n';
    }

    for (int i = 0; i < c; ++i) {
        cout << i << " :";
        for (auto& j : g[i]) cout << ' ' << j;
        cout << '\n';
    }

    int go = min(c + c, k);
    k -= go;

    int p = 0, q = 1;
    vector<vector<int>> save(2, vector<int>(c, -1));
    for (int i = 0; i < c; ++i) return 0;
}