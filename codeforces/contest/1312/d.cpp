#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int M = 998244353;
const int N = 2e5 + 1;
vll fac(N, 1);

void init() {
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
}

ll fpow(ll b, ll n, ll m = M) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * b) % m;
        n >>= 1;
        b = (b * b) % m;
    }
    return res;
}
ll gcdex(ll b, ll m) { return fpow(b, m - 2, m); }
ll C(ll k, ll n) {
    if (k > n || k < 0 || n < 0) return 0;
    return fac[n] * gcdex(fac[k], M) % M * gcdex(fac[n - k], M) % M;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    if (n == 2) {
        cout << "0\n";
        return;
    }

    cout << C(n - 1, m) * (n - 2) % M * fpow(2, n - 3) % M << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}