#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << 9 << (n == 1 ? "\n" : "");
    n--;
    for (int x = 8; n--; x = (x + 1) % 10) cout << x << (n > 0 ? "" : "\n");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}