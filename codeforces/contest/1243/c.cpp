#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    vector<bool> chk(1e6, false);
    vector<long long> divisor;
    for (int i = 2; i < 1e6; ++i) {
        if (!chk[i]) {
            if (n % i == 0) divisor.push_back(i);
            while (n % i == 0) n /= i;

            int j = i + i;
            while (j < int(1e6)) {
                chk[j] = true;
                j += i;
            }
        }
    }

    if (n != 1LL) divisor.push_back(n);

    long long res = divisor[0];
    for (int i = 1; i < divisor.size(); ++i) res = __gcd(res, divisor[i]);

    cout << res << '\n';

    return 0;
}