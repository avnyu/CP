#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a;
        cin >> a;
        int cnt = 0;
        while (a) {
            cnt += a & 1;
            a >>= 1;
        }
        cout << (1LL << cnt) << '\n';
    }

    return 0;
}