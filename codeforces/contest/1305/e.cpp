#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
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

void solve() {
    const ll N = 5001;
    ll n, m;
    cin >> n >> m;
    vector<ll> mx(N), res(n);
    iota(all(res), 1);
    for (ll i = 1; i < N; ++i)
        for (ll j = 1; j <= i; ++j) mx[i] += (j - 1) / 2;

    if (m > mx[n]) {
        cout << "-1\n";
        return;
    }

    ll x = 1e9;
    for (ll i = n; i--;) {
        if (mx[i + 1] == m) {
            break;
        } else if (m > mx[i]) {
            res[i] += (mx[i + 1] - m) * 2;
            break;
        } else {
            res[i] = x;
            x -= 5e4;
        }
    }

    for (ll i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
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
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}