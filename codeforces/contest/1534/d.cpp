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
#define prt(u, v) \
    for (auto x = u; x != v;) cout << (*x) << " \n"[++x == v];

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

vi ask(int d, int n) {
    cout << "? " << d << endl;
    vi a(n);
    for (int i = 1; i < n; ++i) cin >> a[i];
    return a;
}
void out(vi &par) {
    cout << "!" << endl;
    for (size_t i = 2; i < par.size(); ++i) cout << par[i] << ' ' << i << endl;
}
void test(int d, vi &par, vi &a) {
    vi b = ask(d, par.size());

    for (size_t i = 1; i < par.size(); ++i)
        if (b[i] == 1) {
            if (a[i] < a[d])
                par[d] = i;
            else
                par[i] = d;
        }
}
void solve() {
    int n;
    cin >> n;

    vi par(n + 1);
    vi h = ask(1, par.size());
    for (size_t i = 2; i < par.size(); ++i)
        if (h[i] == 1) par[i] = 1;

    vvi u(2);
    for (size_t i = 2; i < par.size(); ++i) u[h[i] % 2].push_back(i);

    int c = u[0].size() < u[1].size() ? 0 : 1;
    for (int v : u[c]) test(v, par, h);

    out(par);
}
int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

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