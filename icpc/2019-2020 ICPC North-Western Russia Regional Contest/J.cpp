#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)),
        c(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }

    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int u = j - i, v = j;
            int s = 0;
            for (int k = u + 1; k < v; ++k) s = (s + a[u][k] * b[k][v]) % 10;
            b[u][v] = (a[u][v] != s);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << b[i][j];
        }
        cout << '\n';
    }

    return 0;
}