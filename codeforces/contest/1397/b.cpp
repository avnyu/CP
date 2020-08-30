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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    ll ans = 0;
    for (auto& i : a) ans += i - 1;
    const ll M = 1e13;
    for (int i = 2; i < 100000; ++i) {
        ll x = 1;
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (x > M) {
                ok = false;
                break;
            }
            x *= i;
        }
        if (ok) {
            ll res = 0;
            x = 1;
            for (int j = 0; j < n; ++j) {
                res += abs(x - a[j]);
                x *= i;
            }
            ans = min(ans, res);
        }
    }
    print(ans);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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