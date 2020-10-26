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
    int n, m;
    cin >> n >> m;
    vii a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].se;
        a[i].fi = i;
    }
    sort(all(a), [](ii a, ii b) {
        return a.se < b.se || (a.se == b.se && a.fi < b.fi);
    });
    int res = 0;
    vi dp(n);
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            if (a[i].se > a[j].se && abs(a[i].fi - a[j].fi) <= m)
                dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
    print(res);
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