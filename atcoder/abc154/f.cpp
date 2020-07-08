#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define rep(i, a, b) for (auto i = a; i != b; i += 1 - 2 * (a > b))

using namespace std;

const int M = 1e9 + 7;
vi fac(2e6 + 7, 1);

ll fpow(ll b, ll n, ll m = M) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * b) % m;
        n >>= 1;
        b = (b * b) % m;
    }
    return res;
}

ll gcdex(ll x, ll m = M) { return fpow(x, m - 2, m); }
ll f(int i, int j) {
    return (((1LL * fac[i + j] * gcdex(fac[i])) % M) * gcdex(fac[j])) % M;
}

void solve() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    for (int i = 2; i < int(2e6 + 7); ++i) fac[i] = (1LL * fac[i - 1] * i) % M;
    // f[i, x..y] = f[i + 1, y] - f[i + 1, x - 1]
    // f[x..y, j] = f[y, j + 1] - f[x - 1, j + 1]


    r2++, c2++;
    cout << (1LL * f(r2, c2) + M - f(r2, c1) + M - f(r1, c2) + f(r1, c1)) % M
         << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;

    while (t--) solve();
    return 0;
}