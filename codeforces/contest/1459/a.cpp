#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    int a[3] = {};
    for (int i = 0; i < n; ++i) a[s[i] > t[i] ? 2 : (s[i] == t[i] ? 1 : 0)]++;
    cout << (a[2] > a[0] ? "RED" : (a[2] == a[0] ? "EQUAL" : "BLUE")) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}