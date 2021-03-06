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

vector<map<int, int>> a(2e5 + 7);
vi par(2e5 + 7, -1);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (a[u].size() < a[v].size()) swap(u, v);
    for (auto& i : a[v]) a[u][i.fi] += i.se;
    par[v] = u;
}
void solve(int T) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a[i + 1][c]++;
    }
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            merge(x, y);
        else {
            x = root(x);
            cout << (a[x].find(y) != a[x].end() ? a[x][y] : 0) << '\n';
        }
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