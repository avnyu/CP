#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvii vector<vector<ii>>
#define vvl vector<vector<ll>>
#define fi first
#define se second
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
    vi a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vl l(n + 2), r(n + 2), p(n + 2);

    int ps = 0;
    p[ps++] = 0;
    for (int i = 1; i <= n; ++i) {
        while (a[p[ps - 1]] > a[i]) ps--;
        l[i] = l[p[ps - 1]] + (i - p[ps - 1]) * a[i];
        p[ps++] = i;
    }
    ps = 0;
    p[ps++] = n + 1;
    for (int i = n; i > 0; --i) {
        while (a[p[ps - 1]] > a[i]) ps--;
        r[i] = r[p[ps - 1]] + (p[ps - 1] - i) * a[i];
        p[ps++] = i;
    }
    int x = 0;
    for (int i = 1; i <= n; ++i)
        if (l[x] + r[x] - a[x] < l[i] + r[i] - a[i]) x = i;

    p[x] = a[x];
    for (int i = x - 1; i; --i) p[i] = min(p[i + 1], 1LL * a[i]);
    for (int i = x + 1; i <= n; ++i) p[i] = min(p[i - 1], 1LL * a[i]);

    for (int i = 1; i <= n; ++i) cout << p[i] << " \n"[i == n];
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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