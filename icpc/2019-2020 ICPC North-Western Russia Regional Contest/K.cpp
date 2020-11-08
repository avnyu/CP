#include <bits/stdc++.h>
using namespace std;

void fill(vector<vector<char>>& mat, int ui, int di, int lj, int rj) {
    if (ui > di || lj > rj) return;

    vector<pair<int, int>> pos;
    for (int i = ui; i <= di; ++i)
        for (int j = lj; j <= rj; ++j)
            if (mat[i][j] > 65 && mat[i][j] < 97) pos.push_back({i, j});
    int n = pos.size();

    int i = 0, j = 0;
    while (i < n) {
        while (j < n && pos[i].first == pos[j].first) j++;

        int up_i = (i == 0 ? ui : pos[i - 1].first + 1);
        int dw_i = (j == n ? di : pos[i].first);

        for (int jj = i; jj < j; ++jj) {
            int lf_j = (jj == i ? lj : pos[jj - 1].second + 1);
            int rg_j = (jj == j - 1 ? rj : pos[jj].second);

            char x = mat[pos[jj].first][pos[jj].second] + 32;
            for (int ci = up_i; ci <= dw_i; ++ci)
                for (int cj = lf_j; cj <= rg_j; ++cj)
                    mat[ci][cj] = (mat[ci][cj] == '.' ? x : mat[ci][cj]);
        }

        i = j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);

    int n, m, i, j;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    pair<int, int> a;

    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                a = {i, j};
                mat[i][j] = '.';
            }
        }

    vector<int> up(m, -1), down(m, -1);
    up[a.second] = down[a.second] = 1;

    i = a.first, j = a.second;

    while (i >= 0 && mat[i][j] == '.') i--;
    up[j] = i + 1;
    i = a.first;

    while (i < n && mat[i][j] == '.') i++;
    down[j] = i - 1;
    i = a.first;

    for (j = a.second - 1; j >= 0; --j) {
        if (mat[i][j] != '.') break;

        while (i >= 0 && mat[i][j] == '.') i--;
        up[j] = max(i + 1, up[j + 1]);
        i = a.first;

        while (i < n && mat[i][j] == '.') i++;
        down[j] = min(i - 1, down[j + 1]);
        i = a.first;
    }

    for (j = a.second + 1; j < m; ++j) {
        if (mat[i][j] != '.') break;

        while (i >= 0 && mat[i][j] == '.') i--;
        up[j] = max(i + 1, up[j - 1]);
        i = a.first;

        while (i < n && mat[i][j] == '.') i++;
        down[j] = min(i - 1, down[j - 1]);
        i = a.first;
    }

    int max_area = 0, upi, upj, downi, downj;
    for (int jl = a.second; jl >= 0; --jl) {
        if (up[jl] == -1) break;

        for (int jr = a.second; jr < m; ++jr) {
            if (up[jr] == -1) break;

            int w = jr - jl + 1;
            int h = min(down[jr], down[jl]) - max(up[jr], up[jl]) + 1;

            if (w * h > max_area) {
                max_area = w * h;
                upi = max(up[jl], up[jr]);
                downi = min(down[jl], down[jr]);
                upj = jl;
                downj = jr;
            }
        }
    }

    for (int i = upi; i <= downi; ++i)
        for (int j = upj; j <= downj; ++j) mat[i][j] = 'a';

    i = a.first, j = a.second;
    mat[i][j] = 'A';

    vector<tuple<char, int, int>> save;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            if (mat[i][j] > 65 && mat[i][j] < 97)
                save.push_back({mat[i][j] + 32, i, j});

    i = a.first, j = a.second;
    fill(mat, 0, upi - 1, 0, m - 1);
    fill(mat, upi, downi, 0, upj - 1);
    fill(mat, upi, downi, downj + 1, m - 1);
    fill(mat, downi + 1, n - 1, 0, m - 1);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) cout << mat[i][j];
        cout << '\n';
    }

    return 0;
}