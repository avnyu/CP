#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    const int M = 1e9 + 7;

    int dp[n + 1][n + 1][3];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n + 1; ++k) 
            for (int j = 0; j <= i; ++j) {
                if (s[i] == 'W'){
                    
                }
            }

    return 0;
}