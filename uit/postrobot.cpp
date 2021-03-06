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
const int M = 1e9 + 7;
const int lgN = 17;
int n, m;
vi h(N), pass(N);
vvi par(N, vi(lgN, -1)), g(N);
vvii reg(N);
vi dp(1 << 12);
vvi before(12, vi(12));
vi p2(22);
vector<vvi> b1s(13), b0s(13);

void cal(int u, int p = -1, int hgt = 1) {
    if (pass[u]) return;
    pass[u] = 1;
    h[u] = hgt;
    par[u][0] = p;
    for (auto& v : g[u]) cal(v, u, hgt + 1);
}
void init_sparse() {
    for (int j = 1; j < lgN; ++j)
        for (int i = 0; i < n; ++i)
            if (par[i][j - 1] != -1) par[i][j] = par[par[i][j - 1]][j - 1];
}
ii lca(int u, int v) {
    bool swaped = h[u] > h[v];
    if (h[u] > h[v]) swap(u, v);
    for (int i = lgN; i--;)
        if ((h[v] - p2[i]) >= h[u]) v = par[v][i];
    if (u == v) return swaped ? ii{-1, -1} : ii{-2, -2};
    for (int i = lgN; i--;)
        if (h[u] - p2[i] >= 0 && par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return swaped ? ii{v, u} : ii{u, v};
}
int cal_ans(int u) {
    int nu = g[u].size();
    for (int i = 0; i < nu; ++i)
        for (int j = 0; j < nu; ++j) before[i][j] = 0;
    for (int i = 0; i < p2[nu]; ++i) dp[i] = 0;
    dp[0] = 1;

    for (auto& r : reg[u]) {
        r.fi = lower_bound(g[u].begin(), g[u].end(), r.fi) - g[u].begin();
        r.se = lower_bound(g[u].begin(), g[u].end(), r.se) - g[u].begin();
        before[r.fi][r.se] = 1;
    }

    for (int msk = 0; msk < p2[nu]; ++msk) {
        for (auto& b1 : b0s[nu][msk]) {
            bool ok = true;
            for (auto& b2 : b1s[nu][msk])
                if (before[b1][b2]) {
                    ok = false;
                    break;
                }
            if (ok) dp[msk | p2[b1]] = (dp[msk | p2[b1]] + dp[msk]) % M;
        }
    }
    return dp[p2[nu] - 1] % M;
}
void init() {
    for (int i = 0; i < 22; ++i) p2[i] = 1 << i;
    for (int i = 0; i < 13; ++i) {
        b1s[i].resize(1 << i);
        b0s[i].resize(1 << i);
        for (int msk = 0; msk < p2[i]; ++msk) {
            for (int b = 0; b < i; ++b)
                if (msk & p2[b])
                    b1s[i][msk].push_back(b);
                else
                    b0s[i][msk].push_back(b);
        }
    }
}
int get_int() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}
void solve(int T) {
    init();
    n = get_int();
    m = get_int();
    for (int i = 1; i < n; ++i) {
        int u = get_int(), v = get_int();
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cal(0);

    g.clear();
    g.resize(N);

    for (int i = 1; i < n; ++i) g[par[i][0]].push_back(i);

    init_sparse();

    for (int i = 0; i < m; ++i) {
        int f, s, u = get_int(), v = get_int();
        u--, v--;
        tie(f, s) = lca(u, v);
        if (f == -1) {
            cout << "0\n";
            return;
        } else if (f != -2)
            reg[par[f][0]].push_back(ii{f, s});
    }
    ll res = 1;
    for (int i = 0; i < n; ++i) {
        res = res * cal_ans(i) % M;
        if (res == 0) break;
    }
    cout << res << '\n';
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
        cout << x << endl;
    }
}