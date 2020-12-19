#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n), x(n);
    for (int i = 0; i < n; ++i) cin >> t[i] >> x[i];

    int bg = 0, ed = 0, tm = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] >= tm) {
            bg = ed;
            ed = x[i];
            tm = t[i] + abs(ed - bg);
        } else {
            bg += ed > bg ? t[i] - t[i - 1] : t[i - 1] - t[i];
        }

        int nx = i < n - 1 ? min(tm, t[i + 1]) : tm;
        int rg = bg + (ed > bg ? nx - t[i] : t[i] - nx);

        if (bg <= x[i] && x[i] <= rg) res++;
        else if (rg <= x[i] && x[i] <= bg) res++;
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}