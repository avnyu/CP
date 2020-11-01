#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int M = 998244353;
const int N = 3e5 + 7;
vll fact(N, 1);

void init() {
    for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % M;
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
ll gcdex(ll x) { return fpow(x, M - 2, M); }
ll C(ll a, ll b) {
    return fact[b] * gcdex(fact[a]) % M * gcdex(fact[b - a]) % M;
}
void solve() {
    int n;
    cin >> n;
    vi a(n + n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0; i < n; ++i) res = (res + a[n + i] - a[i]) % M;
    res = res * C(n, n + n) % M;
    print(res);
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

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T x, Args... args) {
    if (sizeof...(args)) {
        cout << x << ' ';
        print(args...);
    } else {
        cout << x << '\n';
    }
}