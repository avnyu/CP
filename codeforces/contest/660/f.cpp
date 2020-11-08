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
using namespace __gnu_pbds;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 1 << 18;
const ll M = 1e18 + 7;
vector<pair<ll, ll>> it(N << 1);
vi lef(N << 1), rig(N << 1);

void asg(int i = 1, int l = 0, int r = N - 1) {
    lef[i] = l;
    rig[i] = r;
    if (l == r) return;
    int m = l + r >> 1;
    asg(i << 1, l, m);
    asg(i << 1 | 1, m + 1, r);
}
ll get(pair<ll, ll>& d, int p) { return d.fi * p + d.se; }
void update(int i, pair<ll, ll> v) {
    if (get(it[i], lef[i]) > get(v, lef[i]) &&
        get(it[i], rig[i]) > get(v, rig[i]))
        it[i] = v;
    else if (get(it[i], lef[i]) <= get(v, lef[i]) &&
             get(it[i], rig[i]) <= get(v, rig[i]))
        return;
    else {
        update(i << 1, v);
        update(i << 1 | 1, v);
    }
}
ll query(int p, int i = 1) {
    if (p < lef[i] || p > rig[i]) return M;
    ll res = get(it[i], p);
    if (lef[i] == rig[i]) return res;
    res = min(res, query(p, i << 1));
    res = min(res, query(p, i << 1 | 1));
    return res;
}
void add(int b, int e, pair<ll, ll> v, int i = 1) {
    if (rig[i] < b || lef[i] > e) return;
    if (b <= lef[i] && rig[i] <= e) {
        update(i, v);
        return;
    }
    add(b, e, v, i << 1);
    add(b, e, v, i << 1 | 1);
}
void solve() {
    int n;
    cin >> n;
    vll pfs(n + 2), res(n + 2), a(n + 2);

    for (int i = n; i; i--) cin >> a[i];
    for (int i = 0; i++ < n;) pfs[i] = pfs[i - 1] + a[i];
    for (int i = 0; i++ < n;) res[i] = res[i - 1] + pfs[i - 1] + a[i];

    ll ans = 0;
    for (int i = 0; i++ < n;) {
        ans = max(ans, res[i]);
        ans = max(ans, res[i] - query(i));
        add(i, n, pair<ll, ll>{pfs[i], res[i] - pfs[i] * i});
    }

    print(ans);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    asg();

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