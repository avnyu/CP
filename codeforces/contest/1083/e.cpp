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
#define pll pair<ll, ll>

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

namespace CHT {
const ll M = INT64_MAX;
vector<pll> cht;
ll intersect(pll x, pll y) { return (x.se - y.se) / (y.fi - x.fi); }
void add(pll line) {
    if (st.size() && st.back().fi == line.fi) st.pop_back();
    while () }
void add_lines(vector<pll> lines) {
    int n = lines.size();
    sort(lines.begin(), lines.end());
    for (int i = 0; i < n; ++i) add(lines[i]);
}
ll get(ll x) {
    int p = int(pt.size()) - 1, add = 1 << 17;
    while (add) {
        if (p - add >= 0 && x < pt[p - add]) p -= add;
        add >>= 1;
    }
    p--;
    ll ans = x * st[p].fi + st[p].se;
    return ans;
}
}  // namespace CHT

void solve() {
    int n;
    cin >> n;
    vvll a(n, vll(3));
    for (auto &i : a)
        for (auto &j : i) cin >> j;
    sort(a.begin(), a.end());

    // for (int i = 0; i < n; ++i)
    //     for (int j = 0; j < 3; ++j) cout << a[i][j] << " \n"[j == 2];

    ll res = 0;
    const int maxN = 1e9;
    CHT::add(1, maxN, pll{0, 0}, 1, 1, maxN);

    for (int i = 0; i < n; ++i) {
        auto &x = a[i][0], &y = a[i][1], &v = a[i][2];

        ll cur = CHT::query(y, 1, 1, maxN);
        // print("query", y, cur);
        res = max(res, cur + x * y - v);

        // print("add", -x, cur);
        CHT::add(1, maxN, pll{-x, cur + x * y - v}, 1, 1, maxN);
    }
    print(res);
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