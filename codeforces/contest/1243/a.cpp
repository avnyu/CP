#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& i : a) cin >> i;

        sort(a.begin(), a.end());

        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (a[n - i] >= i)
                res = i;
            else
                break;

        cout << res << '\n';
    }

    return 0;
}