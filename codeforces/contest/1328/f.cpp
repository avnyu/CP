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

int n, k;
vi a;
ll cost(int t) {
    ll costlef = 0, costrig = 0;
    for (int i = 0; i < k; ++i) costlef += a[k - 1] - a[i];
    for (int i = n - k; i < n; ++i) costrig += a[i] - a[n - k];
    return min(costlef, costrig);
}
void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));

    if(k == n || cost(k) > cot())

    ll res = 1e9, l = a[k - 1], r = a[n - k];
    while (l <= r) {
        ll m1 = (l + l + r) / 3, m2 = ();
    }
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