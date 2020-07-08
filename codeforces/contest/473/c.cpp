#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a - 1; i >= b; --i)
#define vi vector<int>
#define piii pair<int, pair<int, int> >
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define m(i, j) map<i, j>
#define F first
#define S second
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    string s[n];
    m(string, ll) rs;
    int a[n];
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> a[i];
    int t, mn;
    rep(i, 0, k) {
        mn = INT_MAX;
        cin >> t;
        int p[t];
        rep(j, 0, t) cin >> p[j], mn = min(mn, a[p[j] - 1]);
        rep(j, 0, t) rs[s[p[j] - 1]] = (ll)mn;
    }
    ll price = 0;
    rep(i, 0, m) {
        cin >> s[0];
        price += rs[s[0]];
    }
    cout << price;
    return 0;
}
