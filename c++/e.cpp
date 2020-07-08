#include <bits/stdc++.h>
using namespace std;

int n, m, o;
string tu;
vector<string> o_chu;
vector<vector<int>> da_su_dung;

bool tim_kiem_quay_lui(int x, int y, int p) {
    // cout << x << ' ' << y << '\n';
    if (p == o) return true;

    if (x < 0 || x == n) return false;
    if (y < 0 || y == m) return false;
    if (o_chu[x][y] != tu[p]) return false;

    if (da_su_dung[x][y]) return false;
    da_su_dung[x][y] = 1;

    for (int i = -1; i < 2; i += 2) {
        if (tim_kiem_quay_lui(x + i, y, p + 1)) return true;
        if (tim_kiem_quay_lui(x, y + i, p + 1)) return true;
        if (tim_kiem_quay_lui(x + i, y + i, p + 1)) return true;
        if (tim_kiem_quay_lui(x + i, y - i, p + 1)) return true;
    }

    da_su_dung[x][y] = 0;
    return false;
}

int main() {
    string s;
    cin >> tu;

    while (1) {
        cin >> s;
        if (s == ".") break;
        o_chu.push_back(s);
    }

    o = tu.size();
    n = o_chu.size();
    m = o_chu[0].size();
    da_su_dung.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (tim_kiem_quay_lui(i, j, 0)) {
                cout << "true";
                return 0;
            }
    cout << "false";

    return 0;
}