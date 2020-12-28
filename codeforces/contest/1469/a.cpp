#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s.size() & 1 || s[0] == ')' || s.back() == '(') {
        cout << "NO\n";
        return;
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