#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;
    int cur = n, prv = 0;
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        cur -= a - prv;
        if (cur <= 0) ok = false;
        
        cur += b - a;
        
        cur = min(cur, n);

        prv = b;
    }
    cur -= t - prv;
    if (cur <= 0) ok = false;

    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}