#include <bits/stdc++.h>

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
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve(int T) {
    int n;
    cin >> n;
    vl d(n + n);
    for (int i = 0; i < n + n; ++i) cin >> d[i];
    sort(d.begin(), d.end());

    bool ok = true;
    for (ll i = 0; i < n; ++i)
        if (d[i << 1] != d[i << 1 | 1] || d[i << 1] & 1)
            ok = false;
        else
            d[i] = d[i << 1] >> 1;

    for (ll i = n; i--;) {
        if (i < n - 1) d[i] -= d[i + 1];

        if (d[i] % (i + 1)) ok = false;
        d[i] /= (i + 1);

        if (i < n - 1) d[i] += d[i + 1];
    }
    for (ll i = 1; i < n; ++i) d[i - 1] -= d[i];

    for (ll i = 0; i < n; ++i)
        if (d[i] <= 0) ok = false;

    for (int i = 1; i < n; ++i)
        if (d[i - 1] >= d[i]) ok = false;

    print(ok ? "YES" : "NO");
    // prt(d);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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