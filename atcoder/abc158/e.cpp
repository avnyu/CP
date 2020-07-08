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
template <typename T>
void print_all(vector<T>& a);

ll fpow(ll b, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1) res = (res * b) % m;
        n >>= 1;
        b = (b * b) % m;
    }
    return res;
}
ll gcdex(ll u, ll m) { return fpow(u, m - 2, m); }

void solve() {
    ll n, p;
    string s;
    cin >> n >> p >> s;

    if (p == 2 || p == 5) {
        ll res = 0;
        for (int i = 0; i < n; ++i) res += (s[i] - '0') % p == 0 ? i + 1 : 0;
        cout << res << '\n';
        return;
    }

    vll m(n + 1), a(p);
    for (int i = n; i--;) {
        m[i] = (s[i] - '0') * fpow(10, n - i - 1, p) % p;
        m[i] = (m[i] + m[i + 1]) % p;
        a[m[i]]++;
    }

    ll res = 0, x = 0;
    for (int i = n; i--;) {
        res += a[x];
        a[m[i]]--;
        x = m[i] % p;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}