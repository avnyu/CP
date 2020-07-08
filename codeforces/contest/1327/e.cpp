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

const int M = 998244353;
ll fpow(ll b, ll n, ll m = M) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * b % m;
        n >>= 1;
        b = b * b % m;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    ll sum = 0, par_sum = 0;
    vi res(n);
    for (int i = 0; i < n; ++i) {
        par_sum = (par_sum + sum) % M;
        res[i] = (fpow(10, i + 1) * (i + 1) % M - par_sum + M) % M;
        sum = (sum + res[i]) % M;
        par_sum = (par_sum + res[i]) % M;
    }
    for (int i = n; i--;) cout << res[i] << " \n"[!i];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
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