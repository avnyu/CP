#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 3);
    for (int i = 0; i < n; ++i) cin >> a[i + 3];

    sort(a.begin(), a.end());

    for (int i = 2; i <= n + 2; ++i)
        a[i] = ((n + 2 - i) % 2 == a[i] % 2 ? a[i] : 0) + a[i - 2];

    if (a[n + 2] > a[n + 1])
        cout << "Alice\n";
    else if (a[n + 2] == a[n + 1])
        cout << "Tie\n";
    else
        cout << "Bob\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}