#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3, res = 0;
    vector<int> lis(n), a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.begin() + k1);
    sort(a.begin() + k1, a.begin() + k1 + k2);
    sort(a.begin() + k1 + k2, a.end());

    for (int i = 0; i < n; ++i) {
        int p = upper_bound(lis.begin(), lis.begin() + res, a[i]) - lis.begin();
        res += p == res;
        lis[p] = a[i];
    }

    cout << n - res << '\n';

    return 0;
}