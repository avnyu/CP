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

const int N = 1 << 17;
const ll M = 1e18 + 7;
vector<pair<ll, ll>> it(N << 1);
vi low(N << 1), high(N << 1);

void init() {
    int cur, h, m;
    m = 32 - __builtin_clz(N);
    for (int i = 1; i < N << 1; ++i) {
        if (!(i & (i - 1))) cur = 0;
        h = m - (32 - __builtin_clz(i));
        low[i] = cur;
        high[i] = cur + (1 << h) - 1;
        cur += 1 << h;
    }
}
ll get(pair<ll, ll>& d, int p) { return d.fi * p + d.se; }
void update(int i, pair<ll, ll> v) {
    if (get(it[i], low[i]) > get(v, low[i]) &&
        get(it[i], high[i]) > get(v, high[i]))
        it[i] = v;
    else if (get(it[i], low[i]) <= get(v, low[i]) &&
             get(it[i], high[i]) <= get(v, high[i]))
        return;
    else {
        update(i << 1, v);
        update(i << 1 | 1, v);
    }
}
ll query(int p, int i = 1) {
    if (p < low[i] || p > high[i]) return M;
    ll res = get(it[i], p);
    if (low[i] == high[i]) return res;
    res = min(res, query(p, i << 1));
    res = min(res, query(p, i << 1 | 1));
    return res;
}
void add(int b, int e, pair<ll, ll> v, int i = 1) {
    if (high[i] < b || low[i] > e) return;
    if (b <= low[i] && high[i] <= e) {
        update(i, v);
        return;
    }
    add(b, e, v, i << 1);
    add(b, e, v, i << 1 | 1);
}
void solve() {}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

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