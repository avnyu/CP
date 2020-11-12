#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
#define dd pair<double, double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vll vector<pll>
#define vdd vector<dd>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvd vector<vd>
#define vvii vector<vii>
#define vvll vector<vll>
#define vvdd vector<vdd>
#define fi first
#define se second
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

ll get_max(ll x) {
    ll t = 1, res = 0;
    while (t <= x) {
        res = max(res, x / (t * 10) * t + x % t);
        t *= 10;
    }
    return res;
}
ll get_min(ll x) {
    ll t = 1, res = x;
    while (t <= x) {
        res = min(res, x / (t * 10) * t + x % t);
        t *= 10;
    }
    return res;
}
ll cal(ll u, ll v, ll pu, ll pv) {
    ll t = 1;
    while (v % t != v) t *= 10;
    return pu * (u * t + v) - pu * u - pv * v;
}
void solve(int T) {
    vl a;
    vi b = {1};

    ll x, res = 0;
    char c;

    cin >> x;
    a.push_back(x);
    res += x;

    while (cin >> c >> x) {
        b.push_back(c == '+' ? 1 : -1);
        a.push_back(x);
        res += a.back() * b.back();
    }

    int n = a.size();
    ll change = -1e18;
    for (int i = 0; i < n; ++i) {
        change = max(change, b[i] * get_max(a[i]) - b[i] * a[i]);
        change = max(change, b[i] * get_min(a[i]) - b[i] * a[i]);
    }

    for (int i = 1; i < n; ++i)
        change = max(change, cal(a[i - 1], a[i], b[i - 1], b[i]));

    print(res + change);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve(i);

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