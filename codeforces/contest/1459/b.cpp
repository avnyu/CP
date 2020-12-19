#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(1001);
    for (int i = 1; i <= n; ++i) a[i] = (i + 1) / 2 * 4;
    a[4]++;

    int t = n & 1 ? 2 : 4;
    long long res = 0;
    while (n > 0) {
        res += a[n];
        n -= t;
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (; t--;) solve();

    return 0;
}