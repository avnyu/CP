#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    for (long long i = 0, l, r, x; i < n; ++i) {
        cin >> x;
        if (i == 0) {
            l = x;
            r = x;
            // cout << i << " " << l << " " << r << '\n';
            continue;
        }
        if (i == n - 1) {
            l = max(l - k + 1, x);
            r = min(r + k - 1, x);
        } else {
            l = max(l - k + 1, x);
            r = min(r + k - 1, x + k - 1);
        }
        // cout << i << " " << l << " " << r << '\n';
        if (l > r) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}