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

const int M = 1e9 + 7;

struct Query {
    int l, x, index;
};
void add(vi& basis, int& sz, int x) {
    for (int i = 0; i < basis.size(); ++i)
        if (x & 1 << i)
            if (basis[i])
                x ^= basis[i];
            else {
                basis[i] = x;
                sz++;
                break;
            }
}
bool in(vi& basis, int x) {
    for (int i = 0; i < basis.size(); ++i)
        if (x & 1 << i) x ^= basis[i];
    return !x;
}
int fpow(int b, int n, const int m = M) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * b % m;
        n >>= 1;
        b = 1LL * b * b % m;
    }
    return res;
}
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n), basis(20), rs(q);
    vector<Query> qr(q);
    for (auto& i : a) cin >> i;
    for (int i = 0; i < q; ++i) {
        cin >> qr[i].l >> qr[i].x;
        qr[i].index = i;
    }
    sort(all(qr), [](Query& a, Query& b) { return a.l < b.l; });
    int added = 0, sz = 0;
    for (auto& qi : qr) {
        while (added < qi.l) add(basis, sz, a[added++]);
        rs[qi.index] = in(basis, qi.x) ? fpow(2, qi.l - sz) : 0;
    }
    for (auto& i : rs) write(i);
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