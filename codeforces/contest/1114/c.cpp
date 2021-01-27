#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void solve() {
    ll x, y;
    cin >> x >> y;
    vector<bool> a(1000000);
    map<ll, ll> m;
    for (ll i = 2; i < 1000000; ++i) {
        if (!a[i]) {
            while ((y % i) == 0) {
                m[i]++;
                y = y / i;
            }
            if (i > 1000) continue;
            for (int j = i + i; j < 1000000; j += i) a[j] = 1;
        }
    }
    if (y != 1) m[y] = 1;
    ll ans = x;
    for (auto& i : m) {
        ll cnt = 0;
        ll z = x;
        while (z) {
            cnt += z / i.first;
            z /= i.first;
        }
        ans = min(ans, cnt / i.second);
    }
    cout << ans << '\n';
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
