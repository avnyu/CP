#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 9) {
        cout << "No" << '\n';
        return;
    }
    int t = (a + b + c) / 9;
    if (a < t || b < t || c < t) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}