#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int M = 1e9;

void mul(vvi& a, vvi& b) {
    vvi c(2, vi(2, 0));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j] % M) % M;
    a = c;
}
void fpow(vvi& a, int n) {
    vvi res = {{1, 0}, {0, 1}};
    while (n) {
        if (n & 1) mul(res, a);
        mul(a, a);
        n >>= 1;
    }
    a = res;
}
int fib(int n) {
    if (n < 2) return 1;
    vvi a = {{0, 1}, {0, 0}}, b = {{0, 1}, {1, 1}};
    fpow(b, n + 1);
    return b[0][1];
}
void solve(int T) {
    ll a, b;
    while (cin >> a >> b) {
        // cout << a + 1 << ' ' << fib(a + 1) << '\n';
        // cout << b + 2 << ' ' << fib(b + 2) << '\n';
        cout << (fib(b + 2) + M - fib(a + 1)) % M << '\n';
    }
    // for (int i = 1; i < 10; ++i) cout << i << ' ' << fib(i) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

    return 0;
}

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << endl;
    }
}