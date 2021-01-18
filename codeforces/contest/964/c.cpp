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
#define FF first
#define SS second
#define SPD                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
ll M = 1e9 + 9;

ll __pow(ll a, ll b) {
    if (b == 0) return 1;
    ll x = a % M;
    ll rs = 1;
    while (b > 0) {
        if (b % 2 == 1) rs = (rs * x) % M;
        x = (x * x) % M;
        b /= 2;
    }
    return rs;
}
void cal_1(ll n, ll a, ll b, ll k, char c[]) {
    ll DT = 0, EX = 0;
    ll K = min((ll)100000, n + 1);
    rep(i, k, K) c[i] = c[i - k];
    k *= K / k;
    rep(i, 0, k) {
        if (i >= k - (n + 1) % k) {
            EX += (c[i] == '+' ? 1 : -1) * (__pow(a, k - 1 - i) * __pow(b, i)) %
                  M;
            EX = (EX + 2 * M) % M;
        }
        DT += (c[i] == '+' ? 1 : -1) * (__pow(a, k - 1 - i) * __pow(b, i)) % M;
        DT = (DT + 2 * M) % M;
    }
    ll I = n - k + 1, J = 0, RS = 0, tmp;
    while (I >= 0) {
        RS = (RS + ((DT * ((__pow(a, I) * __pow(b, J)) % M)) % M)) % M;
        I -= k;
        J += k;
    }
    J += I;
    RS = (RS + ((EX * __pow(b, J)) % M)) % M;
    cout << RS << '\n';
}
void cal_2(ll n, ll a, ll b, ll k, char c[]) {
    ll DT = 0, EX;
    rep(i, 0, k) {
        DT += (c[i] == '+' ? 1 : -1) * (__pow(a, k - 1 - i) * __pow(b, i)) % M;
        DT = (DT + 2 * M) % M;
    }
    ll I = n - k + 1, J = 0, RS = 0, tmp;
    while (I >= 0) {
        RS = (RS + ((DT * ((__pow(a, I) * __pow(b, J)) % M)) % M)) % M;
        I -= k;
        J += k;
    }
    J += I;
    cout << k << '\n';
    cout << RS << '\n';
}
void solve() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    char c[100000];
    rep(i, 0, k) cin >> c[i];
    cal_1(n, a, b, k, c);
}
int main() {
    SPD;
    solve();
    return 0;
}