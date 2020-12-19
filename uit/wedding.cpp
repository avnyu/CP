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

void solve(int T) {
    int n, q;
    cin >> n >> q;

    vi a(31, 0), b(2e5 + 7);
    int e = 0, p = 0;

    for (int i = 0; i < n; ++i) {
        cin >> b[p];
        for (int j = 0; j < 31; ++j)
            if (1 << j & b[p]) a[j]++;
        p++;
    }

    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            b[p++] = x ^ e;
            for (int j = 0; j < 31; ++j)
                if (1 << j & x) a[j]++;
            ++n;
        } else if (t == 2) {
            x = e ^ b[x - 1];
            for (int j = 0; j < 31; ++j)
                if (1 << j & x) a[j]--;
            --n;
        } else {
            for (int j = 0; j < 31; ++j)
                if (1 << j & x) a[j] = n - a[j];
            e ^= x;
        }

        ll res = 0;
        for (int j = 0; j < 31; ++j) res += (1LL << j) * a[j];
        cout << res << '\n';
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