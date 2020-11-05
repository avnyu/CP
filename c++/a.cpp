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

const ll M = INT64_MAX;

double get(pll x, pll y) { return double(x.se - y.se) / (y.fi - x.fi); }
void solve() {
    int n, m;
    cin >> n;
    vector<pll> lin(n);
    for (int i = 0; i < n; ++i) cin >> lin[i].fi >> lin[i].se;
    sort(lin.rbegin(), lin.rend());

    vector<pll> st;
    for (int i = 0; i < n; ++i) {
        if (st.size() < 2) {
            st.push_back(lin[i]);
            continue;
        }

        while (st.size() > 1) {
            m = st.size();
            pll &x = st[m - 2], &y = st[m - 1], &z = lin[i];
            double c1 = get(x, y), c2 = get(y, z), c3 = get(x, z);

            if (c1 < c2) {
                st.push_back(z);
                break;
            } else if (c3 <= c1) {
                st.pop_back();
            } else {
                break;
            }
        }

        if (st.size() < 2) st.push_back(lin[i]);
    }

    n = st.size();
    cin >> m;

    vector<double> pt = {double(-M)};
    for (int i = 1; i < n; ++i) pt.push_back(get(st[i - 1], st[i]));

    n = pt.size();

    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        int p = n - 1, add = 1 << 17;
        while (add) {
            if (p - add >= 0 && pt[p - add] >= x) p -= add;

            add >>= 1;
        }
        ll ans = x * st[p].fi + st[p].se;
        ans = min(ans, x * st[0].fi + st[0].se);
        print(ans);
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