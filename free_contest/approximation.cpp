#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long double s = 1.0;
    vector<long double>a(n), b(m);
    for (auto&i : a)cin >> i;
    for (auto&j : b)cin >> j;
    int i = 0, j = 0;
    while (1) {
        if (i < n && (s * a[i]) < 1e18) {
            s = s * a[i];
            ++i;
        }
        else if (j < m) {
            s = s / b[j];
            ++j;
        }
        else if (i < n) {
            s = s * a[i];
            ++i;
        }
        else break;
    }
    cout << (long long)s;
    return 0;
}
