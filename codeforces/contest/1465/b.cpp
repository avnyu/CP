#include <bits/stdc++.h>

using namespace std;

bool test(long long n) {
    long long m = n, t;
    while (m) {
        t = m % 10;
        if (t && n % t) return false;
        m /= 10;
    }
    return true;
}
void solve() {
    long long n;
    cin >> n;
    while (1) {
        if (test(n)) break;
        n++;
    }
    cout << n << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (; t--;) solve();

    return 0;
}