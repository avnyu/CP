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

const int N = 1e3 + 7;
vi par(N, -1);

int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
void merge(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    par[u] += par[v];
    par[v] = u;
}
void solve(int T) {
    int n, m;
    cin >> n >> m;
    vvi e(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = vi{w, u, v};
    }
    sort(e.begin(), e.end());
    
    const int M = 2e9 + 7;
    int res = M;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j++ < n;) par[j] = -1;
        int j;
        for (j = i; j < m && -par[root(1)] != n; ++j) merge(e[j][1], e[j][2]);
        if (-par[root(1)] == n) res = min(res, e[j - 1][0] - e[i][0]);
    }

    if (res == M) {
        print("NO");
        return;
    }
    print("YES");
    print(res);
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