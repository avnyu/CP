#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int cnt = 0;
    auto test = [&](int i) {
        if (0 < i && i < n - 1)
            return (a[i] > a[i - 1] && a[i] > a[i + 1]) ||
                   (a[i] < a[i - 1] && a[i] < a[i + 1]);
        return false;
    };
    for (int i = 0; i < n; ++i) cnt += test(i);

    int bst = 0;
    for (int i = 0, cur, tmp; i < n; ++i) {
        cur = test(i - 1) + test(i) + test(i + 1);
        tmp = a[i];
        if (i) {
            a[i] = a[i - 1];
            bst = min(bst, test(i - 1) + test(i) + test(i + 1) - cur);
        }
        if (i < n - 1) {
            a[i] = a[i + 1];
            bst = min(bst, test(i - 1) + test(i) + test(i + 1) - cur);
        }
        a[i] = tmp;
    }
    cout << cnt + bst << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif


    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}