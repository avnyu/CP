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

const int N = 107;
vi par(N, -1);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    par[u] += par[v];
    par[v] = u;
}
void reset() { par.assign(N, -1); }
double dis(ii u, ii v) {
    return sqrt((u.fi - v.fi) * (u.fi - v.fi) + (u.se - v.se) * (u.se - v.se));
}
bool test(vii& a, double r) {
    if (r > 100) return false;

    int n = a.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dis(a[i], a[j]) < r + r) merge(i, j);

    for (int i = 0; i < n; ++i) {
        if (dis(a[i], ii{a[i].fi, 100}) < r + r) merge(i, n);
        if (dis(a[i], ii{a[i].fi, -100}) < r + r) merge(i, n + 1);
    }

    return root(n) != root(n + 1);
}
void solve(int T) {
    int n;
    cin >> n;
    vii a(n);
    for (auto& i : a) cin >> i.fi >> i.se;

    double r = 0, add = 100;
    int cnt = 30;

    while (cnt--) {
        reset();
        if (test(a, r + add)) r += add;
        add /= 2;
    }

    cout << fixed << setprecision(6) << r << '\n';
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