#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define SPD                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

int main() {
    SPD;
    ll n, p;
    cin >> n >> p;
    ll a[n], sum = 0, part = 0, rs = 0;
    rep(i, 0, n) cin >> a[i], sum += a[i];
    rep(i, 0, n - 1) {
        sum -= a[i];
        part += a[i];
        rs = max(rs, sum % p + part % p);
    }
    cout << rs;
    return 0;
}
