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
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    
    if(n == 1){
        print(1, 1);
        print(-a[0]);
        print(1, 1);
        print(0);
        print(1, 1);
        print(0);
        return;
    }

    vvll res(3, vll(n, 0));
    for (ll i = 0; i < n - 1; ++i) {
        res[0][i] = -a[i];
        res[1][i] = a[i];
    }

    res[0][n - 1] = -a[n - 1];
    res[2][n - 1] = a[n - 1];

    print(1, n);
    for (ll i = 0; i < n; ++i) cout << res[0][i] * n << " \n"[i == n - 1];
    print(1, n - 1);
    for (ll i = 0; i < n - 1; ++i)
        cout << res[1][i] * (n - 1) << " \n"[i == n - 2];
    print(2, n);
    for (ll i = 1; i < n; ++i) cout << res[2][i] * (n - 1) << " \n"[i == n - 1];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    ll t = 1;
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