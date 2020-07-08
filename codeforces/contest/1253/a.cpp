#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    int l = 0, r = n - 1;
    while (l < n && a[l] == b[l]) l++;
    while (r >= 0 && a[r] == b[r]) r--;

    if (l == n) {
        cout << "YES\n";
        return;
    }

    if (a[l] > b[l]) {
        cout << "NO\n";
        return;
    }

    for (int i = l; i <= r; ++i) {
        if (a[i] - b[i] != a[l] - b[l]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}