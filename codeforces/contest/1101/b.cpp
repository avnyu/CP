#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int l, r, d;
    cin >> l >> r >> d;
    if (l > d) {
        cout << d << endl;
        return;
    }
    l = r / d * d;
    if (l <= r) l += d;
    cout << l << endl;
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
