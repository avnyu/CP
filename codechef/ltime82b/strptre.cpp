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
#define what_is(x) cerr << #x << " is " << x << endl;

using namespace std;

void write();
template <typename T, typename... Args>
void write(T x, Args... args);

const int M = 1e9 + 7;
const int N = 1 << 17;
vi p(N), p2(N), sp2(N), cnt(N);

ll fpow(ll b, ll n, ll m = M) {
    ll p = 1;
    while (n) {
        if (n & 1) p = (p * b) % m;
        n >>= 1;
        b = (b * b) % m;
    }
    return p;
}
ll gcdex(int n, int m = M) {
    return fpow(n, m - 2, m);
}
void init() {
    p2[0] = 1;
    sp2[1] = 2;
    for (int i = 1; i < N; ++i) p2[i] = 2 * p2[i - 1] % M;
    for (int i = 1; i < N; ++i) cnt[i - 1] = (p2[i] - 1 + M) % M;
    for (int i = 3; i < N; i += 2) sp2[i] = (p2[i] + sp2[i - 2]) % M;
    for (int i = 1; i < N; ++i) {
        p[i] = 2 * p[i - 1] % M;
        int add_root = 2 * sp2[i - (i % 2 == 0)] % M;
        p[i] = (add_root + p[i]) % M;
    }
}
void solve() {
    int n;
    cin >> n;
    int q = 2LL * cnt[n] * (cnt[n] - 1) % M;
    write(p[n] * gcdex(q) % M);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    init();

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x;
    if (sizeof...(args)) {
        cout << ' ';
        write(args...);
    } else
        cout << '\n';
}