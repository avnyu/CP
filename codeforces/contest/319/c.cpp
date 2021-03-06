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
vector<double> pt;
double intersect(pll &x, pll &y) { return double(x.se - y.se) / (y.fi - x.fi); }
void add(pll line) {
    if (cht.size() && cht.back().fi == line.fi) {
        pt.pop_back();
        cht.pop_back();
    }
    while (cht.size() && intersect(cht.back(), line) <= pt.back()) {
        pt.pop_back();
        cht.pop_back();
    }
    pt.push_back(cht.empty() ? -M : intersect(cht.back(), line));
    cht.push_back(line);
}
void add_lines(vector<pll> lines) {
    int n = lines.size();
    sort(lines.begin(), lines.end());
    for (int i = 0; i < n; ++i) add(lines[i]);
}
ll get(ll x) {
    auto p = upper_bound(pt.begin(), pt.end(), double(x)) - pt.begin() - 1;
    return cht[p].fi * x + cht[p].se;
}
}  // namespace CHT

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vll dp(n);
    CHT::add(pll{b[0], 0});
    for (int i = 1; i < n; ++i) {
        dp[i] = CHT::get(a[i]);
        CHT::add(pll{b[i], dp[i]});
    }
    print(dp[n - 1]);
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