#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt[2] = {};
    for (int x; n--;) {
        cin >> x;
        cnt[x - 1]++;
    }

    int s = cnt[0] + cnt[1] + cnt[1];
    if (s & 1 || (s / 2 % 2 == 1 && cnt[0] == 0))
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}