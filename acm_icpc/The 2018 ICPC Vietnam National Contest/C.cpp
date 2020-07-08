#include <bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;
vector<long long> fac(101, 1);

void init() {
    for (int i = 1; i < 101; ++i) fac[i] = (fac[i - 1] * i) % M;
}

long long pow(long long x, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = (res * x) % M;
        n >>= 1;
        x = (x * x) % M;
    }
    return res;
}
long long gcdex(long long x, long long y) { return pow(x, y - 2); }

long long C(long long x, long long y) {
    return (fac[y] * gcdex((fac[x] * fac[y - x]) % M, M)) % M;
}
int main() {
    init();

    long long n, k, s;
    vector<vector<long long>> dp(101, vector<long long>(101, 0));

    cin >> n;
    for (int i = 0; i < 101; ++i) dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
        cout << "1 1 " << i << '\n';
        cout.flush();
        cin >> k >> s;

        long long prv_k = 0, pre_k = 0;

        for (int j = 1; j < i; ++j) {
            prv_k = (prv_k + dp[j][k]) % M;
            pre_k = (pre_k + dp[j][k - 1]) % M;
        }

        if (k == 1) pre_k = 1;

        //cout << "debug " << i << ' ' << prv_k << ' ' << pre_k << '\n';

        dp[i][1] = (s - prv_k + M) % M;
        dp[i][1] = (dp[i][1] * gcdex(pre_k, M)) % M;

        for (int j = 2; j <= i; ++j) {
            long long pre_j = 0;
            for (int jj = 1; jj < i; ++jj) pre_j = (pre_j + dp[jj][j - 1]) % M;
            dp[i][j] = (pre_j * dp[i][1]) % M;
        }
    }

    cout << "2";
    for (int i = 1; i <= n; ++i) cout << ' ' << dp[i][1];

    return 0;
}