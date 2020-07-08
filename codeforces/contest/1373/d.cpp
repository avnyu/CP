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

ll cal(vi& a) {
    ll n = a.size();
    ll res = 0;
    for (int i = 0; i < n; i += 2) res += a[i];
    vi b(n, 0);
    for (int i = 0; i + 1 < n; i += 2) b[i] = a[i + 1] - a[i];
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        if (sum < 0) sum = 0;
        sum += b[i];
        mx = max(mx, sum);
    }
    fill(all(b), 0);
    for (int i = 2; i < n; i += 2) b[i] = a[i - 1] - a[i];
    sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum < 0) sum = 0;
        sum += b[i];
        mx = max(mx, sum);
    }
    return mx + res;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& i : a) cin >> i;

    print(cal(a));
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
    cout << x << ' ';
    print(args...);
}
