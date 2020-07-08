#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        a = abs(a - b);
        a = min(a + x, n - 1);
        cout << a << '\n';
    }
    return 0;
}