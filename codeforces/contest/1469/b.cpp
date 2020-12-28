#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) cin >> r[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    int b1 = 0, b2 = 0;
    for (int i = 0, cur = 0; i < n; ++i) {
        cur += r[i];
        b1 = max(cur, b1);
    }
    for (int i = 0, cur = 0; i < m; ++i) {
        cur += b[i];
        b2 = max(cur, b2);
    }
    cout << b1 + b2 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}