#include <bits/stdc++.h>
using namespace std;

int d_in_m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(string &s, int l, int r) {
    int res = 0;
    for (int i = l; i <= r; ++i) res = 10 * res + s[i] - '0';
    return res;
}
bool chk(string &s) {
    int y = get(s, 0, 3);
    int m = get(s, 4, 5);
    int d = get(s, 6, 7);

    if (m < 1 || m > 12) return false;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        if (m == 2) return (d > 0) && (d < (d_in_m[2] + 2));
    return (d > 0) && (d < (d_in_m[m] + 1));
}

void solve() {
    string d, m, y;
    cin >> d >> m >> y;
    string s = y + m + d;
    sort(s.begin(), s.end());
    string res = "", beg = "20000101";
    int cnt = 0;

    while (1) {
        if (chk(s) && s >= beg) {
            if (res == "") res = s;
            cnt++;
        }
        if (!next_permutation(s.begin(), s.end())) break;
    }

    if (cnt == 0) {
        cout << "0\n";
        return;
    }

    cout << cnt << ' ' << res.substr(6, 2) << ' ' << res.substr(4, 2) << ' '
         << res.substr(0, 4) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}