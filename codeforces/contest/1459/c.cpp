#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if (a.size() == 1) {
        for (int j = 0; j < m; ++j) b[j] = a.front() + b[j];
    } else {
        long long cur = a[1] - a[0];
        for (int i = 1; i < n; ++i) cur = __gcd(cur, a[i] - a[i - 1]);
        for (int j = 0; j < m; ++j) b[j] = __gcd(a[0] + b[j], cur);
    }

    for (auto &j : b) cout << j << " \n"[&j == &b.back()];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (; t--;) solve();

    return 0;
}