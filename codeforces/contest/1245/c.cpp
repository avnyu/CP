#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    s = '0' + s;

    int n = s.size();
    int M = 1e9 + 7;

    vector<int> dp(n, 0);

    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        if (s[i] == 'w') {
            std::cout << "0\n";
            return 0;
        } else if (s[i] == 'm') {
            std::cout << "0\n";
            return 0;
        } else if (s[i] == s[i - 1] && s[i] == 'n')
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;
        else if (s[i] == s[i - 1] && s[i] == 'u')
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;
        else
            dp[i] = dp[i - 1];

        // cout << i << ' ' << dp[i] << '\n';
    }
    std::cout << dp[n - 1] << '\n';

    return 0;
}