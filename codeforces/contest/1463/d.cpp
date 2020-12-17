#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    int l = 0, r = n;
    for (int i = 0; i < n; ++i) {
        l = max(l, i * 2 + 2 - b[i]);
        r = min(r, i * 2 + n + 1 - b[i]);
    }

    // cout << l << " " << r << '\n';
    cout << (r - l + 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}