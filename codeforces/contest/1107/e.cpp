#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll< vvll;

const int N = 1e2+7;
vll bst(N), a(N);
vvll dp(N, vll(N, -1));

ll f(int l, int r) {
    if (l == r) return dp[l][r] = a[1];
    if (dp[l][r] != -1) return dp[l][r];
    
    for (int i = l; i <= r; ++i)
        dp[l][r] = max(dp[l][r], f(l, i) + f(i, r));
    
    for (int i = l; i < r; ++i)
        for (int j = i; j < r; ++j) {
            dp[l][r] = max(f(l, i) + 
        }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i++ < n;) cin >> a[i];
    
    for (int i = 0; i++ < n;)
        for(int j = i; j--;) bst[i] = max(bst[i], bst[j] + a[i - j]);
    
    cout << f(0, n - 1) << '\n';
    
    return 0;
}
