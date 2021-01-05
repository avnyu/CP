#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll h = 0, l = 0, sum = 0;
    for (int i = 0; i < n; ++i) h += (a[i] - 1LL) / x + 1LL;

    sum = accumulate(a.begin(), a.end(), 0LL);

    l = (sum - 1LL) / x + 1LL;

    cout << l << " " << h << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}