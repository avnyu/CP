#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (i >= 1 && !a[i - 1]) a[i] = 1;
        if (i >= 5 && !a[i - 5]) a[i] = 1;
        if (i >= 13 && !a[i - 13]) a[i] = 1;
    }

    cout << a[n] + 1 << '\n';

    return 0;
}
