#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    ll x, y;
    cin >> x >> y;
    cout << (x - 1) * 9 + y << endl;
}
int main() {
    FIO;
    // srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--) { solve(); }
    return 0;
}
