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
vi par(N, -1);
vector<set<int>> notin(N);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    // print("merge", u, v);
    u = root(u), v = root(v);
    if (u == v) return;
    if (-par[u] < -par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    for (auto& i : notin[v])
        if (root(i) != u) notin[u].insert(i);
}
void solve(int T) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i++ < n;) notin[i].insert(i + 1);
    for (int i = 0; i < m; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        // print("query", t, u, v);
        if (t == 1) {
            merge(u, v);
        } else if (t == 2) {
            int r = root(u);
            while (1) {
                auto x = notin[r].lower_bound(u);
                if (x == notin[r].end()) break;
                if (*x > v) break;
                merge(r, *x);
                r = root(r);
                if (notin[r].find(*x) != notin[r].end()) notin[r].erase(*x);
            }
        } else {
            print(root(u) == root(v) ? "YES" : "NO");
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