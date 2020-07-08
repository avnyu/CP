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

int fpow(int b, int n, int m) {
    int res = 1;
    while (n) {
        if (n & 1) res = (res * b) % m;
        n >>= 1;
        b = (b * b) % m;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), cnt(m), in(m);
    for (auto& i : a) cin >> i;
    sort(all(a));
    for (int i = 0; i < n; ++i) a[i] = a[i] % m;

    if (n > m) {
        cout << "0\n";
        return;
    }

    int x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x = (a[i] - j + m) % m;
            cnt[x] += in[j];
        }
        in[a[i]] = (in[a[i]] + 1) % m;
    }
    int res = 1;
    for (int i = 0; i < m; ++i) res = (res * fpow(i, cnt[i], m)) % m;
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
    for (auto i = a.begin(); i != a.end();) cout << *i << " \n"[++i == a.end()];
}