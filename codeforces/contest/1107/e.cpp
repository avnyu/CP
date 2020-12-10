#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vi s(n + 2), a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    transform(s.begin(), s.end(), [](int x) { return x - '0'; });

    ll dp[n + 2][n + 2][2][n + 2] = {};

    for (int l = 1; l <= n; ++l)
        for (int i = 1; i <= n; ++i) {
            int j = i + l - 1;
            int cnt = 0;
            for (int k = i; k <= j; ++k) cnt += s[k] == '0'
        }

    return 0;
}
