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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& i : a) cin >> i;

    sort(a.rbegin(), a.rend());

    ll res = 0, pre = 0;
    for (int i = 0; i < n; ++i) {
        res += pre;
        pre += a[i];
    }

    ll add = 0, mul = 1, cur = 0;
    int j = k, c = k + 1;
    for (int i = n; i--;) {
        pre -= a[i];

        if (j) {
            j--;
            a[i] = 0;
        }

        cur += mul * a[i];
        c--;

        if (c == 0) {
            c = k + 1;
            mul++;
        }

        add = max(add, cur - pre);

        print(cur - pre);
    }

    print(res, res + add);
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