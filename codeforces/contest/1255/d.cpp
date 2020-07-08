#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int N = 101;
int r, c, k, sum;
vector<char> chicken;
vector<vector<char>> grid(N, vector<char>(N));
vector<int> rice(62, 0);

void init() {
    for (int i = 0; i < 128; ++i)
        if (i >= 48 && i <= 57)
            chicken.push_back(i);
        else if (i >= 65 && i <= 90)
            chicken.push_back(i);
        else if (i >= 97 && i <= 122)
            chicken.push_back(i);
}

void solve() {
    cin >> r >> c >> k;

    sum = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
            sum += grid[i][j] == 'R';
        }

    for (int i = 0; i < k; ++i) rice[i] = sum / k;
    for (int i = 0; i < sum % k; ++i) rice[i]++;

    int ci = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            int x = i;
            int y = (i & 1 ? c - 1 - j : j);

            ci += rice[ci] == 0;
            ci = min(ci, k - 1);
            rice[ci] -= grid[x][y] == 'R';
            grid[x][y] = chicken[ci];
        }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cout << grid[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    init();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}