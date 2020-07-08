#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
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
template <typename T>
void print_all(vector<T>& a);

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1), b(m + 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    vi suba, subb;
    int cnt = 0;
    for (int i = 0; i <= n; ++i)
        if (!a[i]) {
            suba.eb(cnt);
            cnt = 0;
        } else
            cnt++;

    cnt = 0;
    for (int i = 0; i <= m; ++i)
        if (!b[i]) {
            subb.eb(cnt);
            cnt = 0;
        } else
            cnt++;

    ll res = 0;
    for (int i = 1; i <= n; ++i)
        if (k % i == 0 && k / i <= m) {
            int j = k / i;
            int x = 0, y = 0;
            for (auto& sub : suba) x += max(0, sub - i + 1);
            for (auto& sub : subb) y += max(0, sub - j + 1);
            res += 1LL * x * y;
        }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}

void write() { cout << "\n"; }
template <typename T, typename... Args>
void write(T x, Args... args) {
    cout << x << ' ';
    write(args...);
}
template <typename T>
void print_all(vector<T>& a) {
    for (int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}