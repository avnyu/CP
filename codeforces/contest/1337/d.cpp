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

const ll M = LLONG_MAX;

ll cal(ll a, ll b, ll c) {
    return (b - a) * (b - a) + (c - a) * (c - a) + (c - b) * (c - b);
}
ll test(vll &a, vll &b, vll &c) {
    ll rs = M;
    for (auto &i : a) {
        ll v = lower_bound(all(c), i) - c.begin();
        if (v == c.size()) continue;

        ll u = lower_bound(all(b), i + c[v] >> 1) - b.begin();
        if (u < b.size()) rs = min(rs, cal(i, b[u], c[v]));
        if (u) rs = min(rs, cal(i, b[u - 1], c[v]));
    }
    return rs;
}
void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    vll red(r), green(g), blue(b);

    for (int i = 0; i < r; ++i) cin >> red[i];
    for (int i = 0; i < g; ++i) cin >> green[i];
    for (int i = 0; i < b; ++i) cin >> blue[i];

    sort(all(red));
    sort(all(green));
    sort(all(blue));

    ll rs = M;
    rs = min(rs, test(red, green, blue));
    rs = min(rs, test(red, blue, green));
    rs = min(rs, test(green, red, blue));
    rs = min(rs, test(green, blue, red));
    rs = min(rs, test(blue, red, green));
    rs = min(rs, test(blue, green, red));

    write(rs);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

    int t = 1;
    cin >> t;
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
