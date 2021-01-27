#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int p = 0, l, r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b;
    for (int i = 1; i < n; ++i) b.push_back(a[i - 1] - a[i]);
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < k - 1; ++i) ans = ans + b[i];
    ans = ans + a[n - 1] - a[0];
    cout << ans;
    return 0;
}