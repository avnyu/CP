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

const int N = 1e4 + 7;
ll cnt[N], cntk[N];

void init() {
    for (int i = 3; i < N; ++i) cnt[i] = 1LL * i * i * i * (i - 2);
    for (int i = 3; i < N; ++i) cntk[i] = cnt[i] - cnt[i - 1];
}
vl get_first(ll k) {
    k--;
    ll m = 0, add = 1 << 20, cntm;
    while (add) {
        if (m + add < N && k >= cnt[m + add]) m += add;
        add >>= 1;
    }
    m++;

    // print(k, k - cnt[m - 1], m, cntk[m]);

    k -= cnt[m - 1];
    // m in pos 4
    // k = cntk[k];
    cntm = (m - 1) * (m - 1) * (m - 1);
    if (k < cntm) {
        vl res = {0, 0, 0, m};
        res[0] = k / (m - 1) / (m - 1) + 1;
        k %= (m - 1) * (m - 1);
        res[1] = k / (m - 1) + 1;
        k %= m - 1;
        res[2] = k + 1;
        return res;
    } else
        k -= cntm;

    // m in pos 3
    cntm = (m - 1) * (m - 1) * (m - 2);
    if (k < cntm) {
        vl res = {0, 0, m, 0};
        res[0] = k / (m - 1) / (m - 2) + 1;
        k %= (m - 1) * (m - 2);
        res[1] = k / (m - 2) + 1;
        k %= m - 2;
        res[3] = k + 3;
        return res;
    } else
        k -= cntm;

    // m in pos 2
    cntm = (m - 1) * m * (m - 2);
    if (k < cntm) {
        vl res = {0, m, 0, 0};
        res[0] = k / m / (m - 2) + 1;
        k %= m * (m - 2);
        res[2] = k / (m - 2) + 1;
        k %= m - 2;
        res[3] = k + 3;
        return res;
    } else
        k -= cntm;

    // m in pos 1
    vl res = {m, 0, 0, 0};
    res[1] = k / m / (m - 2) + 1;
    k %= m * (m - 2);
    res[2] = k / (m - 2) + 1;
    k %= m - 2;
    res[3] = k + 3;
    return res;
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
void print_ans(vl &v) {
    long double a = v[0], b = v[1], c = v[2];
    ll n = v[3];

    bool smaller = false;
    if (max(a, b) >= c) smaller = false;
    if (n * (log(c) - log(max(a, b))) > log(2)) smaller = true;
    smaller = fpow(a, n) + fpow(b, n) < fpow(c, n);

    // cout << m << ' ' << a << ' ' << b << ' ' << c << ' ' << n << '\n';
    cout << a << '^' << n << '+' << b << '^' << n << (smaller ? '<' : '>') << c
         << '^' << n << '\n';
}
void solve(int T) {
    ll lf, rg;
    cin >> lf >> rg;
    for (int i = lf; i <= rg; ++i) {
        auto res = get_first(i);
        // print_ans(x);
        for (auto &j : res) cout << j << " \n"[&j == &res.back()];
    }
    // auto x = get_first(1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    init();

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