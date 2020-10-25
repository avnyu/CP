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

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int M = 1e9 + 7;

bool bs(vi& a, int x, vi& req) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) >> 1;
        if (a[m] < x) {
            l = m + 1;
            req[0]++;
        } else if (a[m] > x) {
            r = m;
            req[1]++;
        } else
            return true;
    }
    return false;
}
void solve() {
    int n, x, p;
    cin >> n >> x >> p;
    vi a(n), r(2, 0);
    iota(all(a), 0);
    bs(a, p, r);

    int small = x - 1, big = n - x;
    ll res = 1;
    while (r[0]--) res = res * small-- % M;
    while (r[1]--) res = res * big-- % M;
    int cnt = big + small;
    if (cnt > 1)
        while (cnt) res = res * cnt-- % M;

    print(res);
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("in", "r", stdin);

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