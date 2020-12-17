#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    long long sum = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        sum2 += (i & 1 ? a[i] : 0);
    }

    if (sum2 + sum2 >= sum)
        for (int i = 0; i < n; ++i)
            cout << (i & 1 ? a[i] : 1) << " \n"[i == n - 1];
    else
        for (int i = 0; i < n; ++i)
            cout << (i & 1 ? 1 : a[i]) << " \n"[i == n - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}