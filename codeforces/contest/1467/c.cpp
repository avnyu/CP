#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<vi> a = {vi(n1), vi(n2), vi(n3)};
    for (auto& i : a)
        for (auto& j : i) cin >> j;

    vi me(3);
    vector<long long> sum(3);
    for (int i = 0; i < 3; ++i) me[i] = *min_element(a[i].begin(), a[i].end());
    for (int i = 0; i < 3; ++i)
        sum[i] = accumulate(a[i].begin(), a[i].end(), 0LL);

    long long res = -1e18;
    for (int i = 0; i < 3; ++i) {
        int u = (i + 1) % 3;
        int v = (i + 2) % 3;

        res = max(res, sum[i] + sum[u] - sum[v]);
        res = max(res, sum[i] + sum[v] - sum[u]);

        res = max(res, sum[i] + sum[u] + sum[v] - me[u] - me[v] - me[u] - me[v]);
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int t = 1;
    // cin >> t;
    for (; t--;) solve();

    return 0;
}