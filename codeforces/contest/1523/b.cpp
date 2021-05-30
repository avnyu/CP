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

void test(int u, int v, int _u, int _v, string t = "") {
    if (_u == -u && _v == -v) print(t);
    if (t.size() == 6) return;
    test(u, v, _u + _v, _v, t + '1');
    test(u, v, _u, _v - _u, t + '2');
}
void solve() {
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    print(n * 3);
    for (int i = 0; i < n; i += 2) {
        print(1, i + 1, i + 2);
        print(1, i + 1, i + 2);
        print(2, i + 1, i + 2);
        print(1, i + 1, i + 2);
        print(1, i + 1, i + 2);
        print(2, i + 1, i + 2);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
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