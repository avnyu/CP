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
    vvll a(n, vll(n));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j) {
            a[i][j] = 1LL << (i * n) + j;
            cout << a[i][j] << " \n"[j == n - 1];
        }
    cout.flush();
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll k;
        cin >> k;
        ll x = 0, y = 0;
        print(x + 1, y + 1);
        while (x != n - 1 || y != n - 1) {
            if (k & (1LL << ((x + 1) * n + y)))
                x++;
            else
                y++;
            print(x + 1, y + 1);
        }
        cout.flush();
    }
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
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