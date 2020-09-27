#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string s;
    cin >> s >> k;
    n = s.size();

    vector<int> a(n + n + 1);
    for (int i = 0; i < n; ++i) a[i + 1] = a[i + n + 1] = s[i] == 'E';
    partial_sum(a.begin(), a.end(), a.begin());

    lli res = 0;
    for (int i = 1; i <= n; ++i) {
        int x = lower_bound(a.begin() + i, a.begin() + i + k, a[i - 1] + 1) -
                a.begin();
        // cout << i << ' ' << x << '\n';
        res += max(0, i + k - x);
    }

    cout << res << '\n';

    return 0;
}