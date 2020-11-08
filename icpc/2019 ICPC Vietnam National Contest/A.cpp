#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == 'M') a[i][j] = -2;
        }

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        int s, x, y;
        tie(s, x, y) = q.front();
        q.pop();

        if (x < 0 || a[x][y] == -2 || (a[x][(y + 1) % m] == -2 && s != 0))
            continue;

        if (a[x][y] >= 0) continue;
        a[x][y] = s;

        if (x == n - 1) {
            cout << s + 1 << '\n';
            return 0;
        }

        int x1, y1, x2, y2, x3, y3, x4, y4;

        x1 = x + 1;
        y1 = (y + m - 1) % m;

        x2 = x - 1;
        y2 = (y + m - 1) % m;

        x3 = x;
        y3 = (y + m - 2) % m;

        x4 = x;
        y4 = (y + m - 1) % m;

        q.push({s + 1, x1, y1});
        q.push({s + 1, x3, y3});
        q.push({s + 1, x2, y2});
        q.push({s + 1, x4, y4});
    }

    cout << "-1\n";

    return 0;
}