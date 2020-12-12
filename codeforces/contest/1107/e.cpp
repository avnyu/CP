#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    
    ll s[n + 2], a[n + 2];
    memset(s, 0, sizeof(s));
    memset(a, 0, sizeof(a));
    
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    ll dp[n + 2][n + 2][2][n + 2];
    memset(dp, 0, sizeof(dp));

    for (auto &i: s) cout << i << " \n"[&i == (s + n + 1)];

    for (int l = 1; l <= n; ++l)
        for (int i = 1; i <= n; ++i) {
            int j = i + l - 1;
            int cnt = 0;
            for (int k = i; k <= j; ++k) cnt += s[k] == '0';
        }

    return 0;
}
