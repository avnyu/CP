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
    int n, d, m;
    cin >> n >> d >> m;
    vll a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vll x, y;
    for (auto& i : a)
        if (i > m)
            x.push_back(i);
        else
            y.push_back(i);

    sort(rall(x));
    sort(rall(y));

    for (int i = 1; i < x.size(); ++i) x[i] += x[i - 1];
    for (int i = 1; i < y.size(); ++i) y[i] += y[i - 1];

    ll ans = y.size() ? y.back() : 0;

    for (int i = 0; i++ < n;) {
        ll need = 1 + 1LL * (i - 1) * (d + 1);
        if (need > n) break;
        ll rm = n - need;
        ll cal = 0;
        int xs = x.size();
        if (xs) cal += x[min(i - 1, xs - 1)];
        ll ys = y.size();
        if (ys && rm) cal += y[min(rm - 1, ys - 1)];
        ans = max(ans, cal);
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