#include <bits/stdc++.h>

using namespace std;

void solve() {
    int w, h, n;
    cin >> w >> h >> n;

    int a = 1, b = 1;
    while (w % 2 == 0) {
        w >>= 1;
        a <<= 1;
    }
    while (h % 2 == 0) {
        h >>= 1;
        b <<= 1;
    };

    cout << (1LL * a * b >= n ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}