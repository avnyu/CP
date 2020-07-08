#include <bits/stdc++.h>
#define lli long long
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), res(n, 2e9);
    for (auto& i : a) cin >> i;

    for (int i = 0; i < n; ++i) {
        int bi;
        cin >> bi;

        for (int j = 0; j < n; ++j) res[j] = min(res[j], abs(a[j] - bi));
    }

    for (int i = 0; i < n; ++i) res[0] = max(res[0], res[i]);
    cout << res[0] << '\n';

    return 0;
}