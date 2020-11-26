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

int test(vii& a, int t) {
    int n = a.size();

    // req 1
    for (auto& [s, e] : a)
        if (s >= e) {
            print("wrong", s, e);
            return 1;
        }

    // req 2
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i].fi == a[j].fi || a[i].se == a[j].se) {
                print("wrong", a[i].fi, a[j].fi);
                print("wrong", a[i].se, a[j].se);
                return 2;
            }

    // req 3
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && a[i].fi < a[j].fi && a[i].se >= a[j].se) {
                print("wrong", a[i].fi, a[i].se);
                print("wrong", a[j].fi, a[j].se);
                return 3;
            }

    for (auto& [s, e] : a)
        if (s > t || e > t) {
            print("wrong", s, e);
            return 4;
        }

    return 0;
}
int root(vi& par, int u) { return par[u] < 0 ? u : par[u] = root(par, par[u]); }
void merge(vi& par, int u, int v) {
    u = root(par, u), v = root(par, v);
    if (u == v) return;
    par[v] = u;
}
int test2(vii& a, vii& b, int n) {
    const int N = 107;
    vi v(N, -1), m(N, -1);

    for (auto& [s, e] : a) merge(v, s, e);
    for (auto& [s, e] : b) merge(m, s, e);

    for (int i = 0; i++ < n;)
        for (int j = 0; j++ < n;)
            if (i != j && root(v, i) == root(v, j) && root(m, i) == root(m, j))
                return 1;
    return 0;
}
void solve(int T) {
    int n, k;
    cin >> n >> k;

    vvi a(11, vi(11));

    vii vina, mobi;

    int t = 0;
    while (t * t < n) t++;
    for (int i = 0; i < t; ++i)
        for (int j = 0; j < t; ++j) a[i + 1][j + 1] = i * t + j + 1;

    int m = 1, x = 0, y = 2;
    for (int i = 1; i < t * t; ++i) {
        if (i < m * (m + 1))
            x++;
        else if (i < (m + 1) * (m + 1))
            y++;

        if (x > 1 && a[x - 1][y] <= n && a[x][y] <= n)
            vina.push_back({a[x - 1][y], a[x][y]});
        if (y > 1 && a[x][y - 1] <= n && a[x][y] <= n)
            mobi.push_back({a[x][y - 1], a[x][y]});

        if (i + 1 == m * (m + 1)) {
            x = m + 1;
            y = 0;
        }
        if (i + 1 == (m + 1) * (m + 1)) {
            x = 0;
            y = m + 2;
            m++;
        }
    }

    if (k > min(mobi.size(), vina.size()))
        print("NO");
    else {
        print("YES");
        for (int i = 0; i < k; ++i) print(vina[i].fi, vina[i].se);
        for (int i = 0; i < k; ++i) print(mobi[i].fi, mobi[i].se);
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
        cout << x << '\n';
    }
}