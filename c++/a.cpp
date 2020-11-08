#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
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

namespace CHT {  // min CHT
const ll M = INT64_MAX;
vector<pll> st;
vector<double> pt;
double get(pll x, pll y) { return double(x.se - y.se) / (y.fi - x.fi); }
void add_lines(vector<pll> lines) {
    int n = lines.size();

    sort(lines.rbegin(), lines.rend());

    for (int i = 0; i < n; ++i) {
        if (st.size() && st.back().fi == lines[i].fi) st.pop_back();

        while (1) {
            if (int(st.size()) < 2) {
                st.push_back(lines[i]);
                break;
            }

            int sts = st.size();
            pll &x = st[sts - 2], &y = st[sts - 1], &z = lines[i];
            double c1 = get(x, y), c2 = get(y, z);

            if (c1 < c2) {
                st.push_back(z);
                break;
            } else
                st.pop_back();
        }
    }

    pt.push_back(-M);
    for (int i = 1; i < int(st.size()); ++i)
        pt.push_back(get(st[i - 1], st[i]));
    pt.push_back(M);
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
    int n, m;
    cin >> n;
    vector<pll> lines(n);
    for (int i = 0; i < n; ++i) cin >> lines[i].fi >> lines[i].se;
    CHT::add_lines(lines);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        print(CHT::get(x));
    }
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