#include <bits/stdc++.h>

#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define ii pair<int, int>
#define vii vector<ii>
#define vvii vector<vii>
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define uni(v) v.erase(unique(v.begin(), v.end()), v.end())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (ll) a / __gcd(a, b) * b
#define prt(v) \
    for (auto& i : v) cout << i << " \n"[&i == &v.back()]
#define gmax(a, b) \
    if (b > a) a = b
#define gmin(a, b) \
    if (b < a) a = b

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

void solve() {
    ll n, p;
    cin >> n >> p;
    vll a(n);
    for (auto& i : a) cin >> i;

    vll b(n);
    partial_sum(a.begin(), a.end(), b.begin());

    ll res = 1e18, pos = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            ll num = 0, cur = 0;

            if (i <= j) {
                num = j - i + 1;
                cur = b[j] - b[i] + a[i];
            } else {
                num = n - (i - j - 1);
                cur = b[n - 1] - (b[i] - b[j] - a[i]);
            }

            if (cur < p) { num += ((p - cur - 1) / b[n - 1] + 1) * n; }

            if (num < res) {
                res = num;
                pos = i;
            }
        }

    print(pos + 1, res);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int i = 0; i++ < t;) solve();

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