#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += x + x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());

    if (n == 2) {
        cout << "-1\n";
        return;
    }

    if (m < n) {
        cout << "-1\n";
        return;
    }

    res += (a[0].first + a[1].first) * (m - n);
    sort(a.begin(), a.end());

    cout << res << '\n';
    for (int i = 0; i < n; ++i) cout << i + 1 << ' ' << (i + 1) % n + 1 << '\n';
    for (int i = 0; i < m - n; ++i)
        cout << a[0].second + 1 << ' ' << a[1].second + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in", "r", stdin);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}