#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    int x = 0, y = 0, sx = n - a, sy = n = b, res = 0;

    while (1) {
        x = min(x + b - a, sx);
        res++;

        if (x == sx) break;

        y = min(y + b - a, sy);
        res++;
    }

    cout << res << '\n';

    return 0;
}