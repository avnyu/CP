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

using namespace std;

void print();
template <typename T, typename... Args>
void print(T x, Args... args);

const int N = 2e5 + 7;
vi par(N, -1), sub(N, 0);

int root(int u) {
    if (par[u] < 0) return u;
    int t = root(par[u]);
    sub[u] += sub[par[u]];
    return par[u] = t;
}
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    sub[v] += 1;
    par[v] = u;
}
void solve(int T) {
    int n, m, shf = 0;
    cin >> n >> m;
    for (; m--;) {
        int t, u, v;
        cin >> t >> u >> v;
        u = (u + shf) % n;
        v = (v + shf) % n;
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