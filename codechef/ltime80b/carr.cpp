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

using namespace std;

const int N = 2, M = 1e9 + 7;
vvi c;

void mul(vvi &a, vvi &b) {
    c = {{0, 0}, {0, 0}};
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                c[i][j] = (1LL * a[i][k] * b[k][j] + c[i][j]) % M;
    a = c;
}

void fpow(vvi &b, ll n, ll m = M) {
    vvi res = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) mul(res, b);
        n >>= 1;
        mul(b, b);
    }
    b = res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << (m % M) << '\n';
        return;
    }

    m %= M;

    vvi b = {{int((m * m - m) % M), int(m)}, {0, 0}};
    vvi x = {{int(m - 1), 1}, {int(m - 1), 0}};
    fpow(x, n - 2);
    mul(b, x);

    cout << ((b[0][0] + b[0][1]) % M) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;

    while (t--) solve();
    return 0;
}