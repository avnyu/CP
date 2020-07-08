#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define iiii tuple<int, int, int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll eulerTotient(ll n) {  // = n (1-1/p1) ... (1-1/pn)
    if (n == 0) return 0;
    ll ans = n;
    for (ll x = 2; x * x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

void solve() {
    ll a, m;
    cin >> a >> m;
    cout << eulerTotient(m / gcd(a, m)) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}