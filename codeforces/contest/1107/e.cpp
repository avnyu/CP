#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void prt(vll &a) {
    for (auto &i : a) cout << i << " \n"[&i == &a.back()];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    vll a(n + 2, 0);
    for (int i = 0; i++ < n;) cin >> a[i];

    vll bst(n + 2);
    for (int i = 0; i++ < n;)
        for (int j = i; j--;) bst[i] = max(bst[i], bst[j] + a[i - j]);
    // prt(bst);

    vll cnt(n + 2);
    for (int i = 0; i++ < n;) cnt[i] = (s[i] == '1') + cnt[i - 1];
    // prt(cnt);

    vvll white(n + 2, vll(n + 2)), black(n + 2, vll(n + 2));
    for (int i = 0; i++ < n;)
        for (int j = i; j <= n; ++j) {
            for (int l = i, r = i; l <= j;) {
                while (r <= j && s[r] == s[l]) ++r;
                if (s[l] == '1') white[i][j] += bst[r - l];
                else black[i][j] += bst[r - l];
                l = r;
            }
        }
    /*
    for (int i = 0; i++ < n;) for (int j = i; j <= n; ++j) cout << i << " " << j << " " << white[i][j] << '\n';
    for (int i = 0; i++ < n;) for (int j = i; j <= n; ++j) cout << i << " " << j << " " << black[i][j] << '\n';
    */
    vvll dp(n + 2, vll(n + 2, 0));
    for (int j = 0; j < n; ++j) for (int i = 1; i + j <= n; ++i) 
        for (int l = i; l <= i + j; ++l) for (int r = l; r <= i + j; ++r) {
            ll w = dp[i][l - 1] + black[l][r] + bst[cnt[r] - cnt[l - 1]] + dp[r + 1][i + j];
            ll b = dp[i][l - 1] + white[l][r] + bst[r + 1 - l - cnt[r] + cnt[l - 1]] + dp[r + 1][i + j];
            ll d = dp[l][r];
                
            dp[i][i + j] = max(dp[i][i + j], max(w, b));
        }
    
    print(dp[1][1]

    cout << dp[1][n] << '\n';

    return 0;
}
