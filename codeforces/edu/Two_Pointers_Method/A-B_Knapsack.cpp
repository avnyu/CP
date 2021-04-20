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
    ll n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;
    vll a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    sort(all(a), greater<ll>());
    partial_sum(all(a), a.begin());

    sort(all(b), greater<ll>());
    partial_sum(all(b), b.begin());

    ll res = 0;
    for (ll i = 0, j = m, w = B * m; i <= n; ++i) {
        while (j > 0 && w > s) {
            w -= B;
            j--;
        }
        if (w <= s) {
            gmax(res, (i > 0 ? a[i - 1] : 0) + (j > 0 ? b[j - 1] : 0));
        }
        w += A;
    }
    print(res);
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