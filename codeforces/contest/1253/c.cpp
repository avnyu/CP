#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    for (int i = 0; i < m; ++i) {
        for (int j = i + m; j < n; j += m) a[j] += a[j - m];
    }
    partial_sum(a.begin(), a.end(), a.begin());
    for (auto& i : a) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}