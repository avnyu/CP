#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n, greater<int>());
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    if (a[0] + a[0] <= sum && sum % 2 == 0)
        cout << "HL\n";
    else
        cout << "T\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}