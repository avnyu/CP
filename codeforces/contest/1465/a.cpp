#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int m = s.size() - 1;
    while (m >= 0 && s[m] == ')') m--;

    cout << (m + 1 < n - m - 1 ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}