#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    int tmp;
    x -= a;
    tmp = min(x, b);
    if (tmp < 0) {
        cout << "NO";
        return;
    }
    b -= tmp;
    x -= tmp;
    if (b > x + y) {
        cout << "NO";
        return;
    }
    tmp = min(y, b);
    y -= tmp;
    if (c > x + y + z) {
        cout << "NO";
        return;
    }
    cout << "YES";
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) { solve(); }
    return 0;
}
