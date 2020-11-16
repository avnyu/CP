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

ll get_max(ll k) {
    // ll t = 3, add = 1024;
    // while (add) {
    //     t += add;
    //     if (t * t * t * (t - 2) < k) t -= add;
    //     add >>= 1;
    // return t + 1;

    ll t = 3;
    while (t * t * t * (t - 2) < k) t++;
    return t;
}
vl get_first(ll k, ll m) {
    k -= (m - 1) * (m - 1) * (m - 1) * (m - 3);

    ll a = k / (m * m * (m - 2));
    k %= (m * m * (m - 2));

    ll b = k / (m * (m - 2));
    k %= (m * (m - 2));

    ll c = k / (m - 2);
    k %= m - 2;

    ll n = k + 2;

    return vl{a + 1, b + 1, c + 1, n + 1};
}
void get_next(vl &v, ll &m) {
    ll &a = v[0], &b = v[1], &c = v[2], &n = v[3];
    if (n < m) {
        n++;
        return;
    }
    if (c < m) {
        c++;
        n = 3;
        return;
    }
    if (b < m) {
        b++;
        c = 1;
        n = 3;
        return;
    }
    if (a < m) {
        a++;
        b = c = 1;
        n = 3;
        return;
    }
    a = b = c = 1;
    n = m + 1;
    m = m + 1;
}
long double fpow(long double b, ll n) {
    long double res = 1;
    while (n) {
        if (n & 1) res *= b;
        n >>= 1;
        b = b * b;
    }
    return res;
}
void print_ans(vl &v, ll m) {
    long double a = v[0], b = v[1], c = v[2];
    ll n = v[3];

    bool smaller = false;
    if (max(a, b) >= c) smaller = false;
    if (n * (log(c) - log(max(a, b))) > log(2)) smaller = true;
    smaller = fpow(a, n) + fpow(b, n) < fpow(c, n);

    cout << m << ' ' << a << ' ' << b << ' ' << c << ' ' << n << '\n';
    // cout << a << '^' << n << '+' << b << '^' << n << (smaller ? '<' : '>') <<
    // c
    //      << '^' << n << '\n';
}
void solve(int T) {
    ll lf, rt;
    cin >> lf >> rt;

    // ll m = get_max(lf);
    // vl v = get_first(lf - 1, m);

    for (int i = lf; i <= rt; ++i) {
        ll m = get_max(i);
        vl v = get_first(i - 1, m);
        print_ans(v, m);
    }
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
        cout << x << endl;
    }
}