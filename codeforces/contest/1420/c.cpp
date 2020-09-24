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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vii b(q);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i)cin >> b[i].fi >> b[i].se;
    vvll dp(n, vll(2));
    for (int i = 0; i < n; ++i) {
        if (!i) {
            dp[i][1] = a[i];
            dp[i][0] = 0;
        } else {
            dp[i][1] = max(dp[i - 1][0] + a[i], dp[i - 1][1]);
            dp[i][0] = max(dp[i - 1][1] - a[i], dp[i - 1][0]);
        }
    }
    print(max(dp[n - 1][0], dp[n - 1][1]));
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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