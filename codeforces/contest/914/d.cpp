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

const int N = 1 << 19;
int st[N << 1];

void mod(int p, int v, int i = 1, int b = 0, int e = N - 1) {
    if (p > e || p < b) return;
    if (b == e) {
        st[i] = v;
        return;
    }
    int m = b + e >> 1;
    mod(p, v, i << 1, b, m);
    mod(p, v, i << 1 | 1, m + 1, e);
    st[i] = gcd(st[i << 1], st[i << 1 | 1]);
}
int get(int l, int r, int x, int i = 1, int b = 0, int e = N - 1) {
    if (l > e || r < b) return 0;
    if (l <= b && e <= r) {
        if (st[i] % x == 0) return 0;
        if (b == e) return st[i] % x != 0;

        if (st[i << 1] % x != 0 && st[i << 1 | 1] % x != 0) return 2;

        int m = b + e >> 1;
        if (st[i << 1] % x != 0) return get(l, r, x, i << 1, b, m);
        return get(l, r, x, i << 1 | 1, m + 1, e);
    }
    int m = b + e >> 1;
    return get(l, r, x, i << 1, b, m) + get(l, r, x, i << 1 | 1, m + 1, e);
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mod(i + 1, x);
    }
    int q;
    cin >> q;
    for (; q--;) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x, cnt = 0, pos;
            cin >> l >> r >> x;
            write(get(l, r, x) > 1 ? "NO" : "YES");
        } else {
            int p, x;
            cin >> p >> x;
            mod(p, x);
        }
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