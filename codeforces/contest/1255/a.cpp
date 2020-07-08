#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int res = 0;
    b -= a;
    res += b / 5;
    b -= (b / 5) * 5;
    res += b / 2;
    b -= (b / 2) * 2;
    res += b;
    cout << res << '\n';
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