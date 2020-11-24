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

const int N = 1e5 + 7;
const int lgN = 20;
vvi par(N, vi(lgN, -1)), g(N), lz(N);
vi res(N), y(N), bit(N);

void add(int p, int v) {
    while (p < bit.size()) {
        bit[p] += v;
        p += p & -p;
    }
}
int get(int p) {
    int res = 0;
    while (p) {
        res += bit[p];
        p -= p & -p;
    }
    return res;
}
void init() {
    for (int j = 1; j < lgN; ++j)
        for (int i = 0; i < par.size(); ++i)
            if (par[i][j - 1] != -1) par[i][j] = par[par[i][j - 1]][j - 1];
}
void dfs(int u) {
    for (auto& i : lz[u]) add(i, 1);
    res[u] = get(y[u]);
    for (auto& v : g[u]) dfs(v);
    for (auto& i : lz[u]) add(i, -1);
}
void solve(int T) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i++ < n;) {
        int p;
        cin >> y[i] >> p;
        if (i > 1) {
            par[i][0] = p;
            g[p].push_back(i);
        }
    }
    init();
    for (; m--;) {
        int o, l, r;
        cin >> o >> l >> r;
        auto find_par = [&](int u, int reg) {
            for (int i = lgN; i--;) {
                if (par[u][i] == -1) continue;
                if (y[par[u][i]] <= reg) u = par[u][i];
            }
            return u;
        };
        o = find_par(o, r);
        lz[o].push_back(l);
    }
    dfs(1);
    for (int i = 0; i++ < n;) cout << res[i] << " \n"[i == n];
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