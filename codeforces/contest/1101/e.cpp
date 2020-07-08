#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int n, w = 0, h = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (x < y) swap(x, y);
        if (c == '+') {
            w = max(w, x);
            h = max(h, y);
        } else {
            cout << ((x >= w & y >= h) ? "YES\n" : "NO\n");
        }
    }
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
